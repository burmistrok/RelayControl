#include "backendapp.h"

#include <QThread>

BackEndApp::BackEndApp(QObject *parent) : QObject(parent)
{

    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &BackEndApp::BackEndAppThread);
    this->timer->start(50);
}

void BackEndApp::start(void)
{
    CommVar = new CommProtocolWraper;
    QObject::connect( this->CommVar, &CommProtocolWraper::DataRecieved, this, &BackEndApp::DataReceived );
    QObject::connect( this->CommVar, &CommProtocolWraper::ReportErrorToApp, this, &BackEndApp::ReportErrorFromComm );
    QObject::connect( this, &BackEndApp::CheckConectionToLLDriver, this->CommVar, &CommProtocolWraper::CheckConection );
    QObject::connect( this, &BackEndApp::WriteDataToDeviceToLLDriver, this->CommVar, &CommProtocolWraper::WriteDataToDevice );
    emit CheckConectionToLLDriver();
}

void BackEndApp::BackEndAppThread(void)
{
    qDebug() << "Someting is runnig";
    this->CommVar->processMsgs();
}


void BackEndApp::GetCmdToDevice(QString Msg)
{
    emit WriteDataToDeviceToLLDriver(Msg);

}

void BackEndApp::ReportErrorFromComm(QString status, QString Data)
{
    emit this->ReportError(status, Data);
}

void BackEndApp::DataReceived(QString Msg)
{
    emit this->ShowStatus(Msg);
}

BackEndApp::~BackEndApp()
{
    if (NULL != CommVar)
    {
        delete CommVar;
    }
}

