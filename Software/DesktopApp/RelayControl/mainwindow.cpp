#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstringlist.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    QStringList simplComboBoxList = {"Norm", "Error"};
    QStringList advenceComboBoxList = {"Norm", "ShToGnd", "ShToBatt"};

    ui->setupUi(this);

    ui->comboBoxErr1_1->addItems( simplComboBoxList );
    ui->comboBoxErr2_1->addItems( advenceComboBoxList );
}

MainWindow::~MainWindow()
{
    delete ui;
}

