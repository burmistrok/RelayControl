#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstringlist.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    QStringList simplComboBoxList = {"Norm", "Error"};
    QStringList advancedComboBoxList = {"Norm", "ShToGnd", "ShToBatt"};

    ui->setupUi(this);

    ui->comboBoxErr1_1->addItems( simplComboBoxList );
    ui->comboBoxErr1_2->addItems( simplComboBoxList );
    ui->comboBoxErr1_3->addItems( simplComboBoxList );
    ui->comboBoxErr1_4->addItems( simplComboBoxList );

    ui->comboBoxErr2_1->addItems( advancedComboBoxList );
    ui->comboBoxErr2_2->addItems( advancedComboBoxList );
    ui->comboBoxErr2_3->addItems( advancedComboBoxList );
    ui->comboBoxErr2_4->addItems( advancedComboBoxList );

    this->isQMessageBoxOpened = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ReporError(QString status, QString Msg)
{

        if (status.contains("ERROR", Qt::CaseInsensitive) )
        {
            QMessageBox::critical(this, status, Msg);
        }
        else if (status.contains("INF", Qt::CaseInsensitive) )
        {
            QMessageBox::information(this, status, Msg);
        }
        else
        {
            QMessageBox::warning(this, status, Msg);
        }
        this->isQMessageBoxOpened = true;
}

void MainWindow::QMessageBoxCloseEvent(void)
{
    this->isQMessageBoxOpened = false;
}

void MainWindow::on_turnOffAllButton_clicked()
{
    emit this->SendCmdToDevice("Hello\n");
}


void MainWindow::GetStatus(QString Msg)
{
    qDebug() << Msg;
}
