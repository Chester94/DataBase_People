#ifndef DIAGRAMDIALOG_H
#define DIAGRAMDIALOG_H

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
           **months,
           **counts;

    int c(double n);

    void setLabel(int *statustic);
    void setMainLayout();
    void drawing(int *statustic);

public:
    DiagramDialog(int *statustic);
};

#endif // DIAGRAMDIALOG_H
