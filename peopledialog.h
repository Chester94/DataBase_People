#ifndef PEOPLEDIALOG_H
#define PEOPLEDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QCalendarWidget>
#include <QComboBox>

#include <QFormLayout>

#include <QDate>

#include <QRegExp>
#include <QRegExpValidator>

#include "people.h"

class PeopleDialog : public QDialog
{
    Q_OBJECT
private:
    // переменные соответсвуют полям таблицы из базы данных
    QLineEdit *surnameEdit,
              *nameEdit,
              *patronomicEdit;
    QComboBox *sexEdit,
              *educationEdit,
              *matrial_statusEdit;
    QCalendarWidget *dateEdit;

    QDialogButtonBox *buttons;

    void createWidgets(); // выделение памяти
    void setValidator(); // установка валидаторов (регулярные выражения, проверка вводимых данных)
    void createComboBox(); // выделение памяти по списки (пол, образование, семейное положение)
    void setCalendar(); // минимальная и максимальная дата в календаре
    void setMainLayout(); // установка расположения виджетов

public:
    PeopleDialog();
    void setPeople(People &p); // устанавливает начальные значения в полях ввода (если необходимо)

    QString getSurname() {return surnameEdit->text();}
    QString getName() {return nameEdit->text();}
    QString getPatronomic() {return patronomicEdit->text();}
    QString getSex() {return sexEdit->currentText();}
    QDate getDate() {return dateEdit->selectedDate();}
    QString getEducation() {return educationEdit->currentText();}
    QString getMatrial_Status() {return matrial_statusEdit->currentText();}

public slots:
    void my_accept(); // измененный слот подтверждения
};

#endif // PEOPLEDIALOG_H
