#include "selectdialog.h"

SelectDialog::SelectDialog()
{
    buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    showAll = new QCheckBox;
    fromDate = new QCalendarWidget;
    toDate = new QCalendarWidget;

    fromDate->setMinimumDate( QDate(1900, 1, 1) );
    toDate->setMinimumDate( QDate(1900, 1, 1) );

    fromDate->setMaximumDate( QDate::currentDate() );
    toDate->setMaximumDate( QDate::currentDate() );

    fromDate->setSelectedDate( QDate(1900, 1, 1) );
    toDate->setSelectedDate( QDate::currentDate() );

    QFormLayout *mainLayout = new QFormLayout;

    mainLayout->addRow("ShowAll", showAll);
    mainLayout->addRow("From", fromDate);
    mainLayout->addRow("To", toDate);
    mainLayout->addRow(buttons);

    setLayout(mainLayout);

    QObject::connect( showAll, SIGNAL( clicked(bool) ), fromDate, SLOT( setDisabled(bool) ) );
    QObject::connect( showAll, SIGNAL( clicked(bool) ), toDate, SLOT( setDisabled(bool) ) );

    QObject::connect( buttons, SIGNAL( accepted() ), this, SLOT( accept() ) );
    QObject::connect( buttons, SIGNAL( rejected() ), this, SLOT( reject() ) );
}
