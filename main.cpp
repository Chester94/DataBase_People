#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QPainter>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    MainWindow *window = new MainWindow;
    window->show();

    QLabel* plbl = new QLabel;
    plbl->setFixedSize(500, 765);

    QObject::connect( window, SIGNAL( closeSignal() ), plbl, SLOT( close() ) );

    QRect rect(plbl->contentsRect());
    QPainter painter;

    QImage resultImage(rect.size(), QImage::Format_ARGB32_Premultiplied);

    painter.begin(&resultImage);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.eraseRect(rect);
    painter.drawImage(rect, resultImage);
    painter.end();

    painter.begin(&resultImage);
    painter.setCompositionMode(QPainter::CompositionMode_Darken);
//    painter.setPen(QPen(QColor(0, 0, 255), 1));
//    painter.setBrush(QBrush(QColor(255, 0, 0)));
//    painter.drawRect(0, 200-100, 100, 100);
    for(int i=0; i < 765; i++)
    {
        if(i<256)
            painter.setPen(QPen(QColor(255, i, 0), 1));
        else if(i < 512)
            painter.setPen(QPen(QColor(511-i, 255, i-256), 1));
            else
                painter.setPen(QPen(QColor(i-512, 765-i, 255), 1));

        //painter.setPen(QPen(QColor(i/2, i/2, i/2), 1));

        painter.drawLine(0, 765-i-1, 500, 765-i-1);
    }
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(rect, resultImage);
    painter.end();

//    int mark=0;
//    double grad = 0;

//    for(int i=0; i < 3; i++)
//    {
//        mark*=120;

//        painter.begin(&resultImage);
//        painter.setCompositionMode(QPainter::CompositionMode_Darken);
//        painter.setPen(QPen(QColor(abs(2-i)*127, abs(1-i)*127, i*127), 1));
//        painter.setBrush(QBrush(QColor(abs(2-i)*127, abs(1-i)*127, i*127)));
//        painter.drawPie(rect, grad, mark*16);
//        grad+=120;
//        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
//        painter.drawImage(rect, resultImage);
//        painter.end();

//        mark/=120;
//        mark++;
//    }

    plbl->setPixmap(QPixmap::fromImage(resultImage));
    plbl->show();

    return app.exec();
}
