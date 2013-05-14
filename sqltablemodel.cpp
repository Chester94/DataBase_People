#include "sqltablemodel.h"

SqlTableModel::SqlTableModel()
{
}

void SqlTableModel::setRec(People &p, int row)
{
    setData( index(row, 1), p.getSurname() );
    setData( index(row, 2), p.getName() );
    setData( index(row, 3), p.getPatronomic() );
    setData( index(row, 4), p.getSex() );
    setData( index(row, 5), p.getDate()/*.toString("dd.MM.yyyy")*/ );
    setData( index(row, 6), p.getEducation() );
    setData( index(row, 7), p.getMatrial_Status() );
    setData( index(row, 8), QDate::currentDate() );
    //setData( index(row, 8), p.getAge() );
    //setData( index(row, 9), p.getEducation() );
    //setData( index(row, 10), p.getMatrial_Status() );
}

void SqlTableModel::addRec(People &p)
{
    int row = rowCount();
    insertRows(row, 1);
    setRec(p, row);
    submitAll();
    setFilter("");
    select();
}

void SqlTableModel::delRec(int row)
{
    deleteRowFromTable(row);
    select();
}

void SqlTableModel::editRec(People &p, int row)
{
    QModelIndex in = index(row, 0);
    QString str = "ID = %1";
    str = str.arg( in.data().toLongLong() );

    setFilter(str);
    select();
    setRec(p, 0);

    submitAll();
    setFilter("");
    select();
}

void SqlTableModel::getRec(People &p, int row)
{
    QModelIndex in = index(row, 1);
    p.setSurname( in.data().toString() );

    in = index(row, 2);
    p.setName( in.data().toString() );

    in = index(row, 3);
    p.setPatronimic( in.data().toString() );

    in = index(row, 4);
    p.setSex( in.data().toString() );

    //qDebug() << index(row, 5).data();
    p.setDate( index(row, 5).data().toDate() );

    in = index(row, 6);
    p.setEducation( in.data().toString() );

    in = index(row, 7);
    p.setMatrialStatus( in.data().toString() );
}

void SqlTableModel::getRecShow(PeopleFull &p, int row)
{
    getRec(p, row);

    QModelIndex in = index(row, 0);
    p.setID( in.data().toLongLong() );

    p.setAge();

    p.setEntryDate( index(row, 8).data().toDate() );
}


Qt::ItemFlags SqlTableModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

QVariant SqlTableModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);

    if ( index.column() == 0 )
        return value.toLongLong();
    if ( index.column() == 1 )
        return value.toString();
    if ( index.column() == 2 )
        return value.toString();
    if ( index.column() == 3 )
        return value.toString();
    if ( index.column() == 4 )
        return value.toString();

    if ( index.column() == 5 )
        if( role == Qt::EditRole )
            return value.toDate().toString("dd.MM.yyyy");
        else
            return value.toDate();

    if ( index.column() == 6 )
        return value.toString();
    if ( index.column() == 7 )
        return value.toString();

    if ( index.column() == 8 )
        if( role == Qt::EditRole )
            return value.toDate().toString("dd.MM.yyyy");
        else
            return value.toDate();
}
