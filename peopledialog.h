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
    QLineEdit *surnameEdit,
              *nameEdit,
              *patronomicEdit;
    QComboBox *sexEdit,
              *educationEdit,
              *matrial_statusEdit;
    QCalendarWidget *dateEdit;

    QDialogButtonBox *buttons;

public:
    PeopleDialog();
    void setPeople(People &p);

    QString getSurname() {return surnameEdit->text();}
    QString getName() {return nameEdit->text();}
    QString getPatronomic() {return patronomicEdit->text();}
    QString getSex() {return sexEdit->currentText();}
    QDate getDate() {return dateEdit->selectedDate();}
    QString getEducation() {return educationEdit->currentText();}
    QString getMatrial_Status() {return matrial_statusEdit->currentText();}

public slots:
    void my_accept();
};

#endif // PEOPLEDIALOG_H
