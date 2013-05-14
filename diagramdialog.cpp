#include "diagramdialog.h"

int DiagramDialog::c(double n)
{
    if(n > 255) return 255;
    if(n < 0) return 0;
    return n;
}

DiagramDialog::DiagramDialog()
{
    diag = new QLabel;

    this->setFixedSize(640, 301);
    diag->setFixedSize(600, 201);

    months = new QLabel*[12];
    counts = new QLabel*[12];

    for(int i = 0; i<12; i++)
    {
        months[i] = new QLabel;
        counts[i] = new QLabel;

        months[i]->setFixedSize(44, 20);
        counts[i]->setFixedSize(44, 20);

        counts[i]->setText("<CENTER>3</CENTER>");
    }

    months[0]->setText("<CENTER>Jan</CENTER>");
    months[1]->setText("<CENTER>Feb</CENTER>");
    months[2]->setText("<CENTER>Mar</CENTER>");
    months[3]->setText("<CENTER>Apr</CENTER>");
    months[4]->setText("<CENTER>May</CENTER>");
    months[5]->setText("<CENTER>June</CENTER>");
    months[6]->setText("<CENTER>July</CENTER>");
    months[7]->setText("<CENTER>Aug</CENTER>");
    months[8]->setText("<CENTER>Sep</CENTER>");
    months[9]->setText("<CENTER>Oct</CENTER>");
    months[10]->setText("<CENTER>Nov</CENTER>");
    months[11]->setText("<CENTER>Dec</CENTER>");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *diagLayout = new QHBoxLayout;
    QHBoxLayout *monthsLayout = new QHBoxLayout;
    QHBoxLayout *countsLayout = new QHBoxLayout;

    diagLayout->addStretch();
    diagLayout->addWidget(diag);
    diagLayout->addStretch();

    monthsLayout->addStretch();
    countsLayout->addStretch();

    for(int i = 0; i < 12; i++)
    {
        monthsLayout->addWidget(months[i]);

        countsLayout->addWidget(counts[i]);
    }

    monthsLayout->addStretch();
    countsLayout->addStretch();

    mainLayout->addStretch();
    mainLayout->addLayout(diagLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(monthsLayout);
    mainLayout->addLayout(countsLayout);
    mainLayout->addStretch();

    this->setLayout(mainLayout);

    QRect rect(diag->contentsRect());
    QPainter painter;

    QImage resultImage(rect.size(), QImage::Format_ARGB32_Premultiplied);

    painter.begin(&resultImage);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.eraseRect(rect);
    painter.drawImage(rect, resultImage);
    painter.end();

    painter.begin(&resultImage);
    painter.setCompositionMode(QPainter::CompositionMode_Darken);

    for(int i=0; i < 201; i++)
    {

        /*if(i < 67)
            painter.setPen( QPen( QColor( 255, c(mc*i), 0 ), 1 ) );
        else if(i < 134)
            painter.setPen( QPen( QColor( c(511-mc*i), 255, c(mc*i-256) ), 1 ) );
        else
            painter.setPen( QPen( QColor( c(mc*i-512), c(765-mc*i), 255), 1 ) );*/

        if(i < 67)
            painter.setPen( QPen( QColor( 255-c(mc*i), c(mc*i), 255 ), 1 ) );
        else if(i < 134)
            painter.setPen( QPen( QColor( c(mc*i-255), 255, c(512-mc*i) ), 1 ) );
        else
            painter.setPen( QPen( QColor( 255, c(770-mc*i), 0), 1 ) );

        painter.drawLine(0, 200-i, 50, 200-i);
        painter.drawLine(50, 200-i/2, 100, 200-i/2);
        painter.drawLine(100, 200-i/3, 150, 200-i/3);
        painter.drawLine(150, 200-i/4, 200, 200-i/4);
        painter.drawLine(200, 200-i/3, 250, 200-i/3);
        painter.drawLine(250, 200-i/2, 300, 200-i/2);
        painter.drawLine(300, 200-i, 350, 200-i);
        painter.drawLine(350, 200-i/2, 400, 200-i/2);
        painter.drawLine(400, 200-i/3, 450, 200-i/3);
        painter.drawLine(450, 200-i/4, 500, 200-i/4);
        painter.drawLine(500, 200-i/3, 550, 200-i/3);
        painter.drawLine(550, 200-i/2, 600, 200-i/2);
    }
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(rect, resultImage);
    painter.end();

    diag->setPixmap(QPixmap::fromImage(resultImage));
}
