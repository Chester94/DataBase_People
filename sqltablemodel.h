#ifndef SQLTABLEMODEL_H
#define SQLTABLEMODEL_H

#include <QtSql>
#include <QModelIndex>

#include "people.h"
#include "peoplefull.h"

class SqlTableModel : public QSqlTableModel
{
private:
    void setRec(People &p, int row); // устанавливает значение записи в целом, используется номер строки

public:
    SqlTableModel();

    void addRec(People &p); // добавление новой записи в таблицу
    void delRec(int row); // удаление записи из таблицы (по номеру строки)
    void editRec(People &p, int row); // внесение изменений в запись (по номеру строки)

    void getRec(People &p, int row); // получение записи из базы (по номеру строки)

    // получение всех данных о записи из базы (по номеру строки) в том числе ID и даты занесения в базу
    void getRecShow(PeopleFull &p, int row);

    Qt::ItemFlags flags(const QModelIndex &index) const; // изменение флагов
    QVariant data(const QModelIndex &index, int role) const; // измененная функция, возвращающая данные
};

#endif // SQLTABLEMODEL_H
