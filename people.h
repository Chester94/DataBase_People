#ifndef PEOPLE_H
#define PEOPLE_H

#include <QString>
#include <QDate>

class People
{
protected:
    QString surname;
    QString name;
    QString patronomic;
    QString sex;
    QDate date;
    QString education;
    QString matrial_status;

public:
    People();

    void setSurname(QString _surname) {surname = _surname;}
    void setName(QString _name) {name = _name;}
    void setPatronimic(QString _patronomic) {patronomic = _patronomic;}
    void setSex(QString _sex) {sex = _sex;}
    void setDate(int d, int m, int y) {date.setDate(y, m, d);}
    void setDate(QDate _date) {date = _date;}
    void setEducation(QString _education) {education = _education;}
    void setMatrialStatus(QString _matrial_status) {matrial_status = _matrial_status;}

    QString getSurname() {return surname;}
    QString getName() {return name;}
    QString getPatronomic() {return patronomic;}
    QString getSex() {return sex;}
    QDate getDate() {return date;}
    int getDay() {return date.day();}
    int getMonth() {return date.month();}
    int getYear() {return date.year();}
    QString getEducation() {return education;}
    QString getMatrial_Status() {return matrial_status;}
};

#endif // PEOPLE_H
