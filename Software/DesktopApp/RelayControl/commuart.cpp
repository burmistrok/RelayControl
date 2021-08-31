#include "commuart.h"
#include <QDebug>

/*Declaration section*/



/*Static variables*/


/*Static functions*/


CommUART::CommUART(QObject *parent) : QObject(parent)
{
}

CommUART::~CommUART()
{
    comPort.close();
}

void CommUART::WriteData(QString Data)
{
    QByteArray BufferArray = Data.toUtf8();
    comPort.write(BufferArray);
}

void CommUART::DataReceived(void)
{
    if(comPort.isOpen())
    {
        QString Data = comPort.readAll();
        if (!Data.isEmpty())
        {
            qDebug() << Data;
            RxBuffer.append(Data);
        }
    }
    else
    {
        emit ReportErrorToDriver("Error", comPort.errorString());
    }
}

bool CommUART::GetData(QString* Data)
{
    bool retVal = false;

    if (!RxBuffer.isEmpty() )
    {
        Data->append(RxBuffer);
        RxBuffer.clear();
        retVal = true;
    }

    return retVal;

}

void CommUART::IsConnected(void)
{
    qDebug() << "Start";
    QObject::connect(&comPort, &QSerialPort::readyRead , this, &CommUART::DataReceived);
    QObject::connect(&comPort, &QSerialPort::errorOccurred, this, &CommUART::ErrorReporByLL_Driver);
    comPort.setPortName("COM4");
    comPort.setBaudRate(QSerialPort::Baud9600);
    if(!comPort.open(QIODevice::ReadWrite))
    {
        emit ReportErrorToDriver("Error", comPort.errorString());
    }
    else
    {
        emit ReportErrorToDriver("Information", "ComPort successfully have been opened");
    }
}


void CommUART::ErrorReporByLL_Driver(QSerialPort::SerialPortError error)
{
    if ( QSerialPort::SerialPortError::NoError != error )
    {
        QString errMsg = comPort.errorString();
        emit ReportErrorToDriver("Error", errMsg );
    }
}

