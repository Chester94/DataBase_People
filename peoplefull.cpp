#include "peoplefull.h"

PeopleFull::PeopleFull()
{
    ID = -1;
    age = 0;
    entryDate.setDate(1, 1, 1);
}

void PeopleFull::setAge()
{
    QDate cur_date = QDate::currentDate();

    if( cur_date < date)
        return;

    age = cur_date.year() - date.year();

    if( cur_date.month() < date.month() )
        age--;

    if( cur_date.month() == date.month() && cur_date.day() < date.day() )
        age--;
}
