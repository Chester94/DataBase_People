#include "mainwindow.h"

MainWindow::MainWindow()
{
    model = NULL;
    view = NULL;
    openBase = closeBase = createBase = clearBase = addRecord = deleteRecord =
            editRecord = showRecord = selectRecord = diagram = NULL;

    createMenu();

    createWidgets();
    setSize();

    setButtonGroupLeftLayout();
    setButtonsGroupRightLayout();
    setMainLayout();

    box = new QWidget;
    box->setLayout(mainLayout);
    setCentralWidget(box);

    setConnect();
}

void MainWindow::createMenu()
{
    QMenu *menuFile = new QMenu("File");
    menuFile->addAction( "Open base", this, SLOT( openBS() ) );
    menuFile->addAction( "Create base", this, SLOT( createBS() ) );
    menuFile->addSeparator();
    menuFile->addAction( "Close base", this, SLOT( closeBS() ) );
    menuFile->addAction( "Clear base", this, SLOT( clearBS() ) );
    menuFile->addSeparator();
    menuFile->addAction( "Quit", this, SLOT( close() ) );

    QMenu *menuEdit = new QMenu("Edit");
    menuEdit->addAction( "Add record", this, SLOT( addRS() ) );
    menuEdit->addAction( "Edit record", this, SLOT( editRS() ) );
    menuEdit->addAction( "Show record", this, SLOT( showRS() ) );
    menuEdit->addAction( "Select records", this, SLOT( selectRS() ) );
    menuEdit->addSeparator();
    menuEdit->addAction( "Delete record", this, SLOT( delRS() ) );

    menuBar()->addMenu(menuFile);
    menuBar()->addMenu(menuEdit);

    menuBar()->addAction( "Diagram", this, SLOT( diagramS() ) );
    menuBar()->addAction( "Help", this, SLOT( helpS() ) );
}

void MainWindow::createWidgets()
{
    view = new QTableView;

    openBase = new QPushButton("Open base");
    closeBase = new QPushButton("Close base");
    createBase = new QPushButton("Create base");
    clearBase = new QPushButton("Clear base");
    addRecord = new QPushButton("Add record");
    deleteRecord = new QPushButton("Del record");
    editRecord = new QPushButton("Edit record");
    showRecord = new QPushButton("Show record");
    selectRecord = new QPushButton("Select");
    diagram = new QPushButton("Diagram");
}

void MainWindow::setSize()
{
    this->setFixedSize(1024, 660);

    view->setFixedSize(732, 569);

    openBase->setFixedSize(72, 72);
    closeBase->setFixedSize(72, 72);
    createBase->setFixedSize(72, 72);
    clearBase->setFixedSize(72, 72);
    deleteRecord->setFixedSize(72, 72);
    addRecord->setFixedSize(72, 72);
    editRecord->setFixedSize(72, 72);
    showRecord->setFixedSize(72, 72);
    selectRecord->setFixedSize(72, 72);
    diagram->setFixedSize(72, 72);
}

void MainWindow::setButtonGroupLeftLayout()
{
    QLabel *openL = new QLabel("<CENTER>Open base</CENTER>");
    QLabel *createL = new QLabel("<CENTER>Create base</CENTER>");
    QLabel *addL = new QLabel("<CENTER>Add record</CENTER>");
    QLabel *editL = new QLabel("<CENTER>Edit record</CENTER>");
    QLabel *selectL = new QLabel("<CENTER>Select</CENTER>");

    buttonGroupLeft = new QVBoxLayout;

    buttonGroupLeft->addStretch();
    buttonGroupLeft->addWidget(openBase);
    buttonGroupLeft->addWidget(openL);

    buttonGroupLeft->addStretch();
    buttonGroupLeft->addWidget(createBase);
    buttonGroupLeft->addWidget(createL);

    buttonGroupLeft->addStretch();
    buttonGroupLeft->addWidget(addRecord);
    buttonGroupLeft->addWidget(addL);

    buttonGroupLeft->addStretch();
    buttonGroupLeft->addWidget(editRecord);
    buttonGroupLeft->addWidget(editL);

    buttonGroupLeft->addStretch();
    buttonGroupLeft->addWidget(selectRecord);
    buttonGroupLeft->addWidget(selectL);

    buttonGroupLeft->addStretch();
}

void MainWindow::setButtonsGroupRightLayout()
{
    QLabel *closeL = new QLabel("<CENTER>Close base</CENTER>");
    QLabel *clearL = new QLabel("<CENTER>Clear base</CENTER>");
    QLabel *delL = new QLabel("<CENTER>Delete record</CENTER>");
    QLabel *showL = new QLabel("<CENTER>Show record</CENTER>");
    QLabel *diagL = new QLabel("<CENTER>Diagram</CENTER>");

    buttonGroupRight = new QVBoxLayout;

    buttonGroupRight->addStretch();
    buttonGroupRight->addWidget(closeBase);
    buttonGroupRight->addWidget(closeL);

    buttonGroupRight->addStretch();
    buttonGroupRight->addWidget(clearBase);
    buttonGroupRight->addWidget(clearL);

    buttonGroupRight->addStretch();
    buttonGroupRight->addWidget(deleteRecord);
    buttonGroupRight->addWidget(delL);

    buttonGroupRight->addStretch();
    buttonGroupRight->addWidget(showRecord);
    buttonGroupRight->addWidget(showL);

    buttonGroupRight->addStretch();
    buttonGroupRight->addWidget(diagram);
    buttonGroupRight->addWidget(diagL);

    buttonGroupRight->addStretch();
}

void MainWindow::setMainLayout()
{
    mainLayout = new QHBoxLayout;

    mainLayout->addStretch();
    mainLayout->addWidget(view);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonGroupLeft);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonGroupRight);
    mainLayout->addStretch();
}

void MainWindow::setConnect()
{
    QObject::connect( openBase, SIGNAL( pressed() ), this, SLOT( openBS() ) );
    QObject::connect( closeBase, SIGNAL( pressed() ), this, SLOT( closeBS() ) );
    QObject::connect( createBase, SIGNAL( pressed() ), this, SLOT( createBS() ) );
    QObject::connect( clearBase, SIGNAL( pressed() ), this, SLOT( clearBS() ) );
    QObject::connect( addRecord, SIGNAL( pressed() ), this, SLOT( addRS() ) );
    QObject::connect( deleteRecord, SIGNAL( pressed() ), this, SLOT( delRS() ) );
    QObject::connect( editRecord, SIGNAL( pressed() ), this, SLOT( editRS() ) );
    QObject::connect( showRecord, SIGNAL( pressed() ), this, SLOT( showRS() ) );
    QObject::connect( selectRecord, SIGNAL( pressed() ), this, SLOT( selectRS() ) );
    QObject::connect( diagram, SIGNAL( pressed() ), this, SLOT( diagramS() ) );
}

void MainWindow::setView()
{
    view->setModel(model);

    view->setColumnWidth(1, 135);
    view->setColumnWidth(2, 135);
    view->setColumnWidth(3, 135);
    view->setColumnWidth(4, 50);
    view->setColumnWidth(5, 95);
    view->setColumnWidth(6, 80);
    view->setColumnWidth(7, 85);

    view->setColumnHidden(0, true);
    view->setColumnHidden(8, true);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    closeBS();

    emit( closeSignal() );

    if(view)
        delete view;

    if(openBase)
        delete openBase;
    if(closeBase)
        delete closeBase;
    if(createBase)
        delete createBase;
    if(clearBase)
        delete clearBase;
    if(addRecord)
        delete addRecord;
    if(deleteRecord)
        delete deleteRecord;
    if(editRecord)
        delete editRecord;
    if(showRecord)
        delete showRecord;
    if(selectRecord)
        delete selectRecord;
    if(diagram)
        delete diagram;

    if(buttonGroupLeft)
        delete buttonGroupLeft;
    if(buttonGroupRight)
        delete buttonGroupRight;
    if(mainLayout)
        delete mainLayout;
    if(box)
        delete box;

    event->accept();
}

void MainWindow::openBS()
{
    QString path = QFileDialog::getOpenFileName( this, tr("Open File"), "D:\\Project\\Qt_Creator\\DataBase_0.6", tr("*.sqlite") );

    if( path != "" )
    {
        closeBS();

        base = QSqlDatabase::addDatabase("QSQLITE");

        base.setDatabaseName(path);

        if( base.open() )
            qDebug() << "Open successful";
        else
        {
            qDebug() << "Open falied";
            return;
        }

        model = new SqlTableModel;
        model->setTable("my_table");
        model->select();
        model->setEditStrategy(QSqlTableModel::OnFieldChange);

        setView();

        this->setWindowTitle(path);
    }
}

void MainWindow::closeBS()
{
    if(model)
        delete model;
    base.close();
    model = NULL;
}

void MainWindow::createBS()
{
    QString path = QFileDialog::getSaveFileName( this, tr("Create File"), "D:\\", tr("*.sqlite") );

    if( path != "" )
    {
        closeBS();

        base = QSqlDatabase::addDatabase("QSQLITE");

        base.setDatabaseName(path);

        if( base.open() )
            qDebug() << "Open successful";
        else
        {
            qDebug() << "Open falied";
            return;
        }

        QSqlQuery query;

        QString str = "CREATE TABLE my_table ("
                "ID integer PRIMARY KEY NOT NULL, "
                "Surname VARCHAR(31), "
                "Name VARCHAR(31), "
                "Patronimic VARCHAR(31), "
                "Sex VARCHAR(6), "
                "Birth date, "
                "Education VARCHAR(10), "
                "MatrialStatus VARCHAR(9), "
                "EntryDate date"
                ");";

        if(query.exec(str))
            qDebug() << "Create successful";
        else
        {
            qDebug() << "Create falied";
            return;
        }

        model = new SqlTableModel;
        model->setTable("my_table");
        model->select();
        model->setEditStrategy(QSqlTableModel::OnFieldChange);

        setView();

        this->setWindowTitle(path);
    }
}

void MainWindow::clearBS()
{
    if(model)
        model->clear();

    QSqlQuery query;

    QString str = "DROP TABLE my_table;";

    query.exec(str);

    closeBS();
}

void MainWindow::addRS()
{
    if(!model)
        return;
    PeopleDialog *dial;
    dial = new PeopleDialog;

    if( dial->exec() == QDialog::Accepted )
    {
        People p;
        p.setSurname( dial->getSurname() );
        p.setName( dial->getName() );
        p.setPatronimic( dial->getPatronomic() );
        p.setSex( dial->getSex() );
        p.setDate( dial->getDate() );
        p.setEducation( dial->getEducation() );
        p.setMatrialStatus( dial->getMatrial_Status() );

        model->addRec(p);
    }

    delete dial;
}

void MainWindow::delRS()
{
    if( view->currentIndex().isValid() )
    {
        int row = view->currentIndex().row();
        model->delRec(row);
    }
}

void MainWindow::editRS()
{
    if( view->currentIndex().isValid() )
    {
        int row = view->currentIndex().row();
        People p;
        model->getRec(p, row);

        PeopleDialog *dial;
        dial = new PeopleDialog;
        dial->setPeople(p);

        if( dial->exec() == QDialog::Accepted )
        {
            p.setSurname( dial->getSurname() );
            p.setName( dial->getName() );
            p.setPatronimic( dial->getPatronomic() );
            p.setSex( dial->getSex() );
            p.setDate( dial->getDate() );
            p.setEducation( dial->getEducation() );
            p.setMatrialStatus( dial->getMatrial_Status() );

            model->editRec(p, row);
        }

        delete dial;
    }
}

void MainWindow::showRS()
{
    if( view->currentIndex().isValid() )
    {
        int row = view->currentIndex().row();
        PeopleFull p;
        model->getRecShow(p, row);

        PeopleShowWidget *pShowW;
        pShowW = new PeopleShowWidget();
        pShowW->setPeopleFull(p);
        pShowW->show();

        QObject::connect( this, SIGNAL( closeSignal() ), pShowW, SLOT( close() ) );
    }
}

void MainWindow::selectRS()
{
}

void MainWindow::diagramS()
{
    /*QLabel* plbl = new QLabel;
    plbl->setFixedSize(500, 765);

    QObject::connect( this, SIGNAL( closeSignal() ), plbl, SLOT( close() ) );

    QRect rect(plbl->contentsRect());
    QPainter painter;

    QImage resultImage(rect.size(), QImage::Format_ARGB32_Premultiplied);

    painter.begin(&resultImage);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.eraseRect(rect);
    painter.drawImage(rect, resultImage);
    painter.end();

    painter.begin(&resultImage);
    painter.setCompositionMode(QPainter::CompositionMode_Darken);

    for(int i = 0; i < 765; i++)
    {
        if(i<256)
            painter.setPen(QPen(QColor(255, i, 0), 1));
        else if(i < 512)
            painter.setPen(QPen(QColor(511-i, 255, i-256), 1));
            else
                painter.setPen(QPen(QColor(i-512, 765-i, 255), 1));

        painter.drawLine(0, i, 500, i);
    }
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(rect, resultImage);
    painter.end();

    plbl->setPixmap(QPixmap::fromImage(resultImage));
    plbl->show();*/

    /*if(!model)
        return;*/
    DiagramDialog *diag;
    diag = new DiagramDialog;

    diag->exec();

    delete diag;
}

void MainWindow::helpS()
{
}
