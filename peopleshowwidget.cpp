#include "peopleshowwidget.h"

PeopleShowWidget::PeopleShowWidget(QWidget *parent) :
    QWidget(parent)
{
    ID = new QLabel;
    Surname = new QLabel;
    Name = new QLabel;
    Partonimic = new QLabel;
    Sex = new QLabel;
    Birth = new QLabel;
    Age = new QLabel;
    Education = new QLabel;
    MatrialStatus = new QLabel;
    EntryDate = new QLabel;

    QFormLayout *mainLayout;
    mainLayout = new QFormLayout;

    mainLayout->addRow("ID: ", ID);
    mainLayout->addRow("Surname: ", Surname);
    mainLayout->addRow("Name: ", Name);
    mainLayout->addRow("Patronimic: ", Partonimic);
    mainLayout->addRow("Sex: ", Sex);
    mainLayout->addRow("Date of birth: ", Birth);
    mainLayout->addRow("Age: ", Age);
    mainLayout->addRow("Education: ", Education);
    mainLayout->addRow("Matrial status: ", MatrialStatus);
    mainLayout->addRow("Date of entry into the database: ", EntryDate);

    setLayout(mainLayout);
}

void PeopleShowWidget::setPeopleFull(PeopleFull &p)
{
    QString str;
    ID->setText( str.setNum( p.getID() ) );
    Surname->setText( p.getSurname() );
    Name->setText( p.getName() );
    Partonimic->setText( p.getPatronomic() );
    Sex->setText( p.getSex() );
    Birth->setText( p.getDate().toString("dd.MM.yyyy") );
    Age->setText( str.setNum( p.getAge() ) );
    Education->setText( p.getEducation() );
    MatrialStatus->setText( p.getMatrial_Status() );
    EntryDate->setText( p.getEntryDate().toString("dd.MM.yyyy") );
}
