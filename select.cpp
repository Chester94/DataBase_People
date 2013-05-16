#include "select.h"

Select::Select()
{
}

void Select::process()
{
    model->setFilter(str);
    model->select();
}
