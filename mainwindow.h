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

#include <QThread>

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
#include "select.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QSqlDatabase base; // база данных (объект для связи)
    SqlTableModel *model; // МВК модель
    QTableView *view; // МВК вид

    // необходимые кнопки для работы с базой
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

    void createMenu(); // создание меню (вверху окна)
    void createWidgets(); // создание виджетов (кнопок), установка текста на кнопках
    void setSize(); // установка размеров рабочего окна, установка размеров кнопок и области отображения данных

    //функции расположения виджетов
    void setButtonGroupLeftLayout();
    void setButtonsGroupRightLayout();
    void setMainLayout();

    void setConnect(); // установка связей
    void setView(); // установка размеров столбцов при отображении, настройка видимости столбцов

    // виртуальный метод, для корректоного завершения при нажатии "крестик"
    virtual void closeEvent(QCloseEvent *event);

public:
    MainWindow();

signals:
    void closeSignal(); // генерируется при закрытии приложения

public slots:
    void openBS(); // открыть базу
    void closeBS(); // закрыть базу
    void createBS(); // создать
    void clearBS(); // очистить
    void addRS(); // добавить запись
    void delRS(); // удалить
    void editRS(); // редактировать
    void showRS(); // показать всю информацию о записи
    void selectRS(); // выборка по дате рождения
    void diagramS(); // нарисовать диагрмму, количество родившихся в каждом месяце
};

#endif // MAINWINDOW_H
