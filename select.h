#ifndef SELECT_H
#define SELECT_H

//#include <QObject>

#include <sqltablemodel.h>

class Select : public QObject
{
    Q_OBJECT
private:
    SqlTableModel *model;
    QString str;

public:
    Select();
    void setModel(SqlTableModel *_model) {model = _model;}
    void setStr(QString _str) {str = _str;}

public slots:
    void process();

signals:
    void finished();

};

#endif // SELECT_H
