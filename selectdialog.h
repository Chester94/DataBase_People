#ifndef SELECTDIALOG_H
#define SELECTDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QCalendarWidget>
#include <QCheckBox>

#include <QFormLayout>

#include <QDate>

// диалог выборки по дате рождения (+ возможность отобразить всех)
class SelectDialog : public QDialog
{
private:
    QCheckBox *showAll; // если нужно отобразить всех людей из таблицы
    QCalendarWidget *fromDate, // от (младше этой даты)
                    *toDate; // до (старше этой даты)

    QDialogButtonBox *buttons;

    void createWidgets(); // выделение памяти
    void setCalendar(); // настройки календарей (минимальная и максимальная даты, текущие даты)
    void setMainLayout(); // установка расположения виджетов

public:
    SelectDialog();

    bool getShowAll() {return showAll->isChecked();}
    QDate getFromDate() {return fromDate->selectedDate();}
    QDate getToDate() {return toDate->selectedDate();}
};

#endif // SELECTDIALOG_H
