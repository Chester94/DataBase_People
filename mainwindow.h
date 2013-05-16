#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QMenu>
#include <QMenuBar>

#include <QtSql>
#include <QTableView>
#include <QModelIndex>
#include <QDate>

#include <QLabel>

#include <QCloseEvent>

#include <QFileDialog>

#include <QList>

#include <QPainter>

#include "peopledialog.h"
#include "peopleshowwidget.h"
#include "sqltablemodel.h"
#include "diagramdialog.h"
#include "selectdialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QSqlDatabase base;
    SqlTableModel *model;
    QTableView *view;

    QPushButton *openBase,
                *closeBase,
                *createBase,
                *clearBase,
                *addRecord,
                *deleteRecord,
                *editRecord,
                *showRecord,
                *selectRecord,
                *diagram;

    QVBoxLayout *buttonGroupLeft, *buttonGroupRight;
    QHBoxLayout *mainLayout;
    QWidget *box;

    void createMenu();
    void createWidgets();
    void setSize();
    void setButtonGroupLeftLayout();
    void setButtonsGroupRightLayout();
    void setMainLayout();
    void setConnect();
    void setView();

    virtual void closeEvent(QCloseEvent *event);

public:
    MainWindow();

signals:
    void closeSignal();

public slots:
    void openBS();
    void closeBS();
    void createBS();
    void clearBS();
    void addRS();
    void delRS();
    void editRS();
    void showRS();
    void selectRS();
    void diagramS();

    void helpS();

    void funS();
};

#endif // MAINWINDOW_H
