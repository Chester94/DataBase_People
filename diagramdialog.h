#ifndef DIAGRAMDIALOG_H
#define DIAGRAMDIALOG_H

// константа дл€ корректного выбора цвета при отображении диаграммы
#define mc 1.9318181818181818181818181818182

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QDialog>

#include <QPainter>

#include <QLabel>

class DiagramDialog : public QDialog
{
    Q_OBJECT
private:
    QLabel *diag,
           **months, // названи€ мес€цев
           **counts; // количество родившихс€ в каждом мес€це

    int c(double n);

    void setLabel(int *statustic); // выделение пам€ти и установка текста надписи
    void setMainLayout(); // установка расположени€ надписей (виджетов)
    void drawing(int *statustic); // рисование диаграммы

public:
    DiagramDialog(int *statustic); // установка размеров, вызов необходимых функций
};

#endif // DIAGRAMDIALOG_H
