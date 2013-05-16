#ifndef SELECTDIALOG_H
#define SELECTDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QCalendarWidget>
#include <QCheckBox>

#include <QFormLayout>

#include <QDate>

class SelectDialog : public QDialog
{
private:
    QCheckBox *showAll;
    QCalendarWidget *fromDate,
                    *toDate;

    QDialogButtonBox *buttons;

public:
    SelectDialog();

    bool getShowAll() {return showAll->isChecked();}
    QDate getFromDate() {return fromDate->selectedDate();}
    QDate getToDate() {return toDate->selectedDate();}
};

#endif // SELECTDIALOG_H
