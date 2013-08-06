#include "peopledialog.h"

PeopleDialog::PeopleDialog()
{
    createWidgets();

    setValidator();

    createComboBox();

    setCalendar();

    setMainLayout();

    QObject::connect( buttons, SIGNAL( accepted() ), this, SLOT( my_accept() ) );
    QObject::connect( buttons, SIGNAL( rejected() ), this, SLOT( reject() ) );
}

void PeopleDialog::createWidgets()
{
    buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    surnameEdit = new QLineEdit;
    nameEdit = new QLineEdit;
    patronomicEdit = new QLineEdit;
    sexEdit = new QComboBox;
    dateEdit = new QCalendarWidget;
    educationEdit = new QComboBox;
    matrial_statusEdit = new QComboBox;
}

void PeopleDialog::setValidator()
{
    QRegExp fioReg("[A-Z][a-z]{,29}");
    QRegExpValidator *fioValidator = new QRegExpValidator(fioReg, this);
    surnameEdit->setValidator(fioValidator);
    nameEdit->setValidator(fioValidator);
    patronomicEdit->setValidator(fioValidator);
}

void PeopleDialog::createComboBox()
{
    QStringList sex;
    sex << "man" << "women";
    sexEdit->addItems(sex);

    QStringList education;
    education << "primary" << "secondary" << "higher";
    educationEdit->addItems(education);

    QStringList matrial_status;
    matrial_status << "free" << "married" << "divorced";
    matrial_statusEdit->addItems(matrial_status);
}

void PeopleDialog::setCalendar()
{
    dateEdit->setMinimumDate( QDate(1900, 1, 1) );
    dateEdit->setMaximumDate( QDate::currentDate() );
}

void PeopleDialog::setMainLayout()
{
    QFormLayout *mainLayout = new QFormLayout;

    mainLayout->addRow("Surname", surnameEdit);
    mainLayout->addRow("Name", nameEdit);
    mainLayout->addRow("Patronomic", patronomicEdit);
    mainLayout->addRow("Sex", sexEdit);
    mainLayout->addRow("Date", dateEdit);
    mainLayout->addRow("Education", educationEdit);
    mainLayout->addRow("Matrial status", matrial_statusEdit);
    mainLayout->addRow(buttons);
    setLayout(mainLayout);
}

void PeopleDialog::setPeople(People &p)
{
    surnameEdit->setText( p.getSurname() );
    nameEdit->setText( p.getName() );
    patronomicEdit->setText( p.getPatronomic() );

    if( p.getSex() == "man")
        sexEdit->setCurrentIndex(0);
    if( p.getSex() == "women")
        sexEdit->setCurrentIndex(1);

    dateEdit->setSelectedDate( p.getDate() );

    if( p.getEducation() == "primary" )
        educationEdit->setCurrentIndex(0);
    if( p.getEducation() == "secondary" )
        educationEdit->setCurrentIndex(1);
    if( p.getEducation() == "higher" )
        educationEdit->setCurrentIndex(2);

    if( p.getMatrial_Status() == "free" )
        matrial_statusEdit->setCurrentIndex(0);
    if( p.getMatrial_Status() == "married" )
        matrial_statusEdit->setCurrentIndex(1);
    if( p.getMatrial_Status() == "divorced" )
        matrial_statusEdit->setCurrentIndex(2);
}

void PeopleDialog::my_accept()
{
    if( surnameEdit->text().trimmed().length() == 0 )
    {
        surnameEdit->setFocus();
        return;
    }

    if( nameEdit->text().trimmed().length() == 0 )
    {
        nameEdit->setFocus();
        return;
    }

    if( patronomicEdit->text().trimmed().length() == 0 )
    {
        patronomicEdit->setFocus();
        return;
    }
    accept();
}
