#include "commprotocolwraper.h"

CommProtocolWraper::CommProtocolWraper(QObject *parent) : QObject(parent)
{
    serialcommWraper = new CommUART;
    QObject::connect(serialcommWraper, &CommUART::ReportErrorToDriver, this, &CommProtocolWraper::ReportError);
}
void CommProtocolWraper::processMsgs(void)
{
    QString Data = nullptr;
    if (false != serialcommWraper->GetData( &Data))
    {
        emit DataRecieved(Data);
    }
}


void CommProtocolWraper::WriteDataToDevice(QString Msg)
{
    this->serialcommWraper->WriteData(Msg);
}

void CommProtocolWraper::CheckConection(void)
{
    this->serialcommWraper->IsConnected();
}

void CommProtocolWraper::ReportError(QString status, QString Data)
{
    emit ReportErrorToApp(status, Data);
}
