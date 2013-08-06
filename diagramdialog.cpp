#include "diagramdialog.h"

int DiagramDialog::c(double n)
{
    if(n > 255) return 255;
    if(n < 0) return 0;
    return n;
}

DiagramDialog::DiagramDialog(int *statustic)
{
    diag = new QLabel;

    this->setFixedSize(640, 501);
    diag->setFixedSize(600, 401);

    setLabel(statustic);

    setMainLayout();

    drawing(statustic);
}

void DiagramDialog::setLabel(int *statustic)
{
    months = new QLabel*[12];
    counts = new QLabel*[12];

    for(int i = 0; i < 12; i++)
    {
        months[i] = new QLabel;
        counts[i] = new QLabel;

        months[i]->setFixedSize(44, 20);
        counts[i]->setFixedSize(44, 20);

        // <CENTER> </CENTER> выравнивание по центру
        counts[i]->setText("<CENTER>"+QString::number(statustic[i])+"</CENTER>");
    }

    months[0]->setText("<CENTER>Jan</CENTER>");
    months[1]->setText("<CENTER>Feb</CENTER>");
    months[2]->setText("<CENTER>Mar</CENTER>");
    months[3]->setText("<CENTER>Apr</CENTER>");
    months[4]->setText("<CENTER>May</CENTER>");
    months[5]->setText("<CENTER>Jun</CENTER>");
    months[6]->setText("<CENTER>Jul</CENTER>");
    months[7]->setText("<CENTER>Aug</CENTER>");
    months[8]->setText("<CENTER>Sep</CENTER>");
    months[9]->setText("<CENTER>Oct</CENTER>");
    months[10]->setText("<CENTER>Nov</CENTER>");
    months[11]->setText("<CENTER>Dec</CENTER>");
}

void DiagramDialog::setMainLayout()
{
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
}

void DiagramDialog::drawing(int *statustic)
{
    int max=0;

    for(int i = 0; i<12; i++)
        if( statustic[i] > max )
            max = statustic[i];

    QRect rect(diag->contentsRect());
    QPainter painter;

    // подготовительные работы
    QImage resultImage(rect.size(), QImage::Format_ARGB32_Premultiplied);

    painter.begin(&resultImage);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.eraseRect(rect);
    painter.drawImage(rect, resultImage);
    painter.end();

    // рисование столбцов диаграммы
    painter.begin(&resultImage);
    painter.setCompositionMode(QPainter::CompositionMode_Darken);

    for(int i=0; i < 402; i++)
    {
        if(i < 134)
            painter.setPen( QPen( QColor( 255-c(mc*i), c(mc*i), 255 ), 1 ) );
        else if(i < 268)
            painter.setPen( QPen( QColor( c(mc*i-255), 255, c(512-mc*i) ), 1 ) );
        else
            painter.setPen( QPen( QColor( 255, c(770-mc*i), 0), 1 ) );

        for(int j = 0; j < 12; j++)
            if(statustic[j])
                painter.drawLine(j*50+2, 400-(i*statustic[j]/max/1.1), (j+1)*50-2, 400-(i*statustic[j]/max/1.1));
    }

    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(rect, resultImage);
    painter.end();

    // конечная устновка
    diag->setPixmap(QPixmap::fromImage(resultImage));
}
