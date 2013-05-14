#ifndef PEOPLESHOW_H
#define PEOPLESHOW_H

#include "people.h"

class PeopleFull : public People
{
private:
    long int ID;
    int age;
    QDate entryDate;

public:
    PeopleFull();

    void setID(long int _ID) {ID = _ID;}
    void setAge(int _age) {age = _age;}
    void setAge();
    void setEntryDate(int d, int m, int y) {entryDate.setDate(y, m, d);}
    void setEntryDate(QDate _entryDate) {entryDate = _entryDate;}

    long int getID() {return ID;}
    int getAge() {return age;}
    QDate getEntryDate() {return entryDate;}
};

#endif // PEOPLESHOW_H
