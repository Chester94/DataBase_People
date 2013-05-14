#ifndef PEOPLESHOWWIDGET_H
#define PEOPLESHOWWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QFormLayout>
//#include <QVBoxLayout>
#include <QDate>

#include "peoplefull.h"

class PeopleShowWidget : public QWidget
{
    Q_OBJECT
private:
    QLabel *ID,
           *Surname,
           *Name,
           *Partonimic,
           *Sex,
           *Birth,
           *Age,
           *Education,
           *MatrialStatus,
           *EntryDate;

public:
    PeopleShowWidget(QWidget *parent = 0);

    void setPeopleFull(PeopleFull &p);
};

#endif // PEOPLESHOWWIDGET_H
