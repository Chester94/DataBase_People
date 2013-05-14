#ifndef SQLTABLEMODEL_H
#define SQLTABLEMODEL_H

#include <QtSql>
#include <QModelIndex>

#include "people.h"
#include "peoplefull.h"

class SqlTableModel : public QSqlTableModel
{
private:
    void setRec(People &p, int row);
public:
    SqlTableModel();

    void addRec(People &p);
    void delRec(int row);
    void editRec(People &p, int row);

    void getRec(People &p, int row);
    void getRecShow(PeopleFull &p, int row);

    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // SQLTABLEMODEL_H
