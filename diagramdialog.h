#ifndef DIAGRAMDIALOG_H
#define DIAGRAMDIALOG_H

#define mc 3.8636363636363636363636363636364

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

public:
    DiagramDialog();
};

#endif // DIAGRAMDIALOG_H
