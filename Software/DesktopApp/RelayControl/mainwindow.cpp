#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    InitActsStr();
    InitActsSts();
    this->isQMessageBoxOpened = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    (void)event;
    emit this->AppWillClose();
}

void MainWindow::FillUpSimpleComboBoxList()
{
    simpleComboBoxList.push_back(QMetaEnum::fromType<CommonData::E_BoxSts>().valueToKey(CommonData::OFF));
    simpleComboBoxList.push_back(QMetaEnum::fromType<CommonData::E_BoxSts>().valueToKey(CommonData::ON));
}

void MainWindow::FillUpAdvanceComboBoxList()
{
    advanceComboBoxList.push_back(QMetaEnum::fromType<CommonData::E_AdvanceComboBoxSts>().valueToKey(CommonData::Normal));
    advanceComboBoxList.push_back(QMetaEnum::fromType<CommonData::E_AdvanceComboBoxSts>().valueToKey(CommonData::ShToBat));
    advanceComboBoxList.push_back(QMetaEnum::fromType<CommonData::E_AdvanceComboBoxSts>().valueToKey(CommonData::ShToGnd));
}

void MainWindow::ActionHandler(int signal, int sts)
{
    if(false == this->as_SignalsState[signal].isStateChangedByGUI)
    {
        emit this->SendCmdToDevice(signal, sts);
    }
    else
    {
        this->as_SignalsState[signal].isStateChangedByGUI = false;
    }
    as_SignalsState[signal].actualSts = sts;
}

void MainWindow::StatusHandler(int signal, int sts)
{
    switch (signal) {

    case CommonData::SimpleRelay1:
    case CommonData::SimpleRelay2:
    case CommonData::SimpleRelay3:
    case CommonData::SimpleRelay4:
    case CommonData::SimpleRelay5:
    case CommonData::AdvanceRelay1:
    case CommonData::AdvanceRelay2:
    case CommonData::AdvanceRelay3:
    case CommonData::AdvanceRelay4:
        this->as_SignalsState[signal].comboBox_ptr->setCurrentIndex(sts);
        break;


    case CommonData::GroupSts:
    case CommonData::Kl15State:
    case CommonData::Kl56State:
    case CommonData::DbgState:
        if( CommonData::OFF == sts)
        {
                this->as_SignalsState[signal].checkBox_ptr->setCheckState(Qt::CheckState::Unchecked);
        }
        else if( CommonData::ON == sts)
        {
                this->as_SignalsState[signal].checkBox_ptr->setCheckState(Qt::CheckState::Checked);
        }
        break;

    }
}

void MainWindow::InitActsSts()
{
    FillUpAdvanceComboBoxList();
    FillUpSimpleComboBoxList();
    ui->comboBoxErr1_1->addItems( simpleComboBoxList );
    ui->comboBoxErr1_2->addItems( simpleComboBoxList  );
    ui->comboBoxErr1_3->addItems( simpleComboBoxList  );
    ui->comboBoxErr1_4->addItems( simpleComboBoxList  );
    ui->comboBoxErr1_5->addItems( simpleComboBoxList  );

    ui->comboBoxErr2_1->addItems( advanceComboBoxList );
    ui->comboBoxErr2_2->addItems( advanceComboBoxList  );
    ui->comboBoxErr2_3->addItems( advanceComboBoxList  );
    ui->comboBoxErr2_4->addItems( advanceComboBoxList  );
}

void MainWindow::InitActsStr()
{

    for (int index = 0; index < CommonData::EndOfSignals ; index++ ) {
        as_SignalsState[index].isStateChangedByGUI = false;
        as_SignalsState[index].actualSts = 0;
        switch (index) {
        case CommonData::SimpleRelay1:
            as_SignalsState[index].comboBox_ptr = ui->comboBoxErr1_1;
            break;
        case CommonData::SimpleRelay2:
            as_SignalsState[index].comboBox_ptr = ui->comboBoxErr1_2;
            break;
        case CommonData::SimpleRelay3:
            as_SignalsState[index].comboBox_ptr = ui->comboBoxErr1_3;
            break;
        case CommonData::SimpleRelay4:
            as_SignalsState[index].comboBox_ptr = ui->comboBoxErr1_4;
            break;
        case CommonData::SimpleRelay5:
            as_SignalsState[index].comboBox_ptr = ui->comboBoxErr1_5;
            break;

        case CommonData::AdvanceRelay1:
            as_SignalsState[index].comboBox_ptr = ui->comboBoxErr2_1;
            break;
        case CommonData::AdvanceRelay2:
            as_SignalsState[index].comboBox_ptr = ui->comboBoxErr2_2;
            break;
        case CommonData::AdvanceRelay3:
            as_SignalsState[index].comboBox_ptr = ui->comboBoxErr2_3;
            break;
        case CommonData::AdvanceRelay4:
            as_SignalsState[index].comboBox_ptr = ui->comboBoxErr2_4;
            break;

        case CommonData::DbgState:
            as_SignalsState[index].checkBox_ptr = ui->BoxDebuger;
            break;

        case CommonData::Kl15State:
            as_SignalsState[index].checkBox_ptr = ui->BoxKL15;
            break;

        case CommonData::Kl56State:
            as_SignalsState[index].checkBox_ptr = ui->BoxKL56;
            break;

        case CommonData::SetAllSignals:
            as_SignalsState[index].checkBox_ptr = ui->UpdBoxSts;
            break;
        }
    }
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
    this->ActionHandler(CommonData::TurnOffAll , 0u);
}


void MainWindow::GetStatus(int signal, int sts)
{
    if (as_SignalsState[signal].actualSts != sts)
    {
        this->as_SignalsState[signal].isStateChangedByGUI = true;
        StatusHandler(signal, sts);
    }
}

void MainWindow::SetInitActuatorMsg(QStringList msgLst)
{
    QString actualMsg;
    for (int i=0; i < msgLst.size(); i++)
    {
        actualMsg.append(msgLst.at(i));
        switch (i) {
        case 0:
            ui->ErrPos1_1->insertPlainText(actualMsg);
            break;
        case 1:
            ui->ErrPos1_2->insertPlainText(actualMsg);
            break;
        case 2:
            ui->ErrPos1_3->insertPlainText(actualMsg);
            break;
        case 3:
            ui->ErrPos1_4->insertPlainText(actualMsg);
            break;
        case 4:
            ui->ErrPos1_5->insertPlainText(actualMsg);
            break;
        case 5:
            ui->ErrPos2_1->insertPlainText(actualMsg);
            break;
        case 6:
            ui->ErrPos2_2->insertPlainText(actualMsg);
            break;
        case 7:
            ui->ErrPos2_3->insertPlainText(actualMsg);
            break;
        case 8:
            ui->ErrPos2_4->insertPlainText(actualMsg);
            break;

        }

        actualMsg.clear();
    }
}


void MainWindow::on_comboBoxErr1_1_currentIndexChanged(const QString &arg1)
{
    this->ActionHandler( CommonData::SimpleRelay1 ,QMetaEnum::fromType<CommonData::E_BoxSts>().keyToValue(arg1.toUtf8()));
}


void MainWindow::on_actionConnect_triggered()
{

}

void MainWindow::on_actionSave_triggered()
{
    QStringList msgLst;
    msgLst.push_back(ui->ErrPos1_1->toPlainText());
    msgLst.push_back(ui->ErrPos1_2->toPlainText());
    msgLst.push_back(ui->ErrPos1_3->toPlainText());
    msgLst.push_back(ui->ErrPos1_4->toPlainText());
    msgLst.push_back(ui->ErrPos1_5->toPlainText());
    msgLst.push_back(ui->ErrPos2_1->toPlainText());
    msgLst.push_back(ui->ErrPos2_2->toPlainText());
    msgLst.push_back(ui->ErrPos2_3->toPlainText());
    msgLst.push_back(ui->ErrPos2_4->toPlainText());
    emit SaveData(msgLst);
}


void MainWindow::on_UpdBoxSts_toggled(bool checked)
{
    int arg1;
    if(checked)
    {
        arg1 = CommonData::ON;
    }
    else
    {
        arg1 = CommonData::OFF;
    }
    this->ActionHandler( CommonData::GroupSts ,arg1);
}

void MainWindow::on_BoxDebuger_toggled(bool checked)
{
    int arg1;
    if(checked)
    {
        arg1 = CommonData::ON;
    }
    else
    {
        arg1 = CommonData::OFF;
    }
    this->ActionHandler( CommonData::DbgState ,arg1);
}

void MainWindow::on_BoxKL15_toggled(bool checked)
{
    int arg1;
    if(checked)
    {
        arg1 = CommonData::ON;
    }
    else
    {
        arg1 = CommonData::OFF;
    }
    this->ActionHandler( CommonData::Kl15State ,arg1);
}

void MainWindow::on_BoxKL56_toggled(bool checked)
{
    int arg1;
    if(checked)
    {
        arg1 = CommonData::ON;
    }
    else
    {
        arg1 = CommonData::OFF;
    }
    this->ActionHandler( CommonData::Kl56State ,arg1);
}

void MainWindow::on_setInitStsButton_clicked()
{
    this->ActionHandler(CommonData::SetInitState, 0u);
}

void MainWindow::on_OnlyDbgButton_clicked()
{
    this->ActionHandler(CommonData::OnlyDbg, 0u);
}

void MainWindow::on_comboBoxErr1_2_currentIndexChanged(const QString &arg1)
{
    this->ActionHandler( CommonData::SimpleRelay2, QMetaEnum::fromType<CommonData::E_BoxSts>().keyToValue(arg1.toUtf8()));
}

void MainWindow::on_comboBoxErr1_3_currentIndexChanged(const QString &arg1)
{
    this->ActionHandler( CommonData::SimpleRelay3, QMetaEnum::fromType<CommonData::E_BoxSts>().keyToValue(arg1.toUtf8()));
}

void MainWindow::on_comboBoxErr1_4_currentIndexChanged(const QString &arg1)
{
    this->ActionHandler( CommonData::SimpleRelay4, QMetaEnum::fromType<CommonData::E_BoxSts>().keyToValue(arg1.toUtf8()));
}

void MainWindow::on_comboBoxErr2_1_currentIndexChanged(const QString &arg1)
{
    this->ActionHandler( CommonData::AdvanceRelay1, QMetaEnum::fromType<CommonData::E_AdvanceComboBoxSts>().keyToValue(arg1.toUtf8()));
}

void MainWindow::on_comboBoxErr2_2_currentIndexChanged(const QString &arg1)
{
    this->ActionHandler( CommonData::AdvanceRelay2, QMetaEnum::fromType<CommonData::E_AdvanceComboBoxSts>().keyToValue(arg1.toUtf8()));
}

void MainWindow::on_comboBoxErr2_3_currentIndexChanged(const QString &arg1)
{
    this->ActionHandler( CommonData::AdvanceRelay3, QMetaEnum::fromType<CommonData::E_AdvanceComboBoxSts>().keyToValue(arg1.toUtf8()));
}

void MainWindow::on_comboBoxErr2_4_currentIndexChanged(const QString &arg1)
{
    this->ActionHandler( CommonData::AdvanceRelay4, QMetaEnum::fromType<CommonData::E_AdvanceComboBoxSts>().keyToValue(arg1.toUtf8()));
}

void MainWindow::on_SendUpdates_clicked()
{
    this->ActionHandler(CommonData::SetAllSignals , 0u);
}

void MainWindow::on_comboBoxErr1_5_currentIndexChanged(const QString &arg1)
{
    this->ActionHandler( CommonData::SimpleRelay5, QMetaEnum::fromType<CommonData::E_BoxSts>().keyToValue(arg1.toUtf8()));
}

void MainWindow::on_actionSupport_triggered()
{
    QMessageBox::information(this, "Some advices", "If you have changed some comments on a error, please save your modifications using Workspace/Save button.\n\r\n\rTo set more than one error in one click concomitant, please use \"Send on click/at command\" box  and \"Send all updates\" button.");
}

void MainWindow::on_actionSource_code_triggered()
{
    QMessageBox::information(this, "Source code", "Source code could be found on\n\rhttps://github.com/burmistrok/RelayControl");
}
