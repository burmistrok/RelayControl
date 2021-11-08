#include "commuart.h"
#include <QDebug>
#include <QFile>

/*Declaration section*/



/*Static variables*/


/*Static functions*/


void CommUART::GetComPortSettings(QString& port, qint32& baudrate)
{
    QFile fileMsg("CommConfigFile.txt");

    if(fileMsg.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream textFile(&fileMsg);
        while(!textFile.atEnd())
        {
            QString tempBuffer;
            bool isFound = false;


            tempBuffer = textFile.readLine();
            if(tempBuffer.contains("COM", Qt::CaseInsensitive))
            {
                port.append(tempBuffer);
                isFound = true;
            }
            tempBuffer = textFile.readLine();
            if(tempBuffer == "9600")
            {
                baudrate = tempBuffer.toInt();
                if(false != isFound)
                {
                    break;
                }
            }

        }
    }
    else
    {
        port.append("COM6");
        baudrate = QSerialPort::Baud9600;
    }
}

CommUART::CommUART(QObject *parent) : QObject(parent)
{
}

CommUART::~CommUART()
{
    comPort.close();
}

void CommUART::WriteData(QByteArray Data)
{
    comPort.write(Data);
}

void CommUART::DataReceived(void)
{
    if(comPort.isOpen())
    {
        QByteArray Data = comPort.readAll();
        if (!Data.isEmpty())
        {
            RxBuffer.append(Data);
        }
    }
    else
    {
        emit ReportErrorToDriver("Error", comPort.errorString());
    }
}

bool CommUART::GetData(QByteArray* Data)
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
    QString port;
    qint32 baudrate = QSerialPort::Baud9600;
    QObject::connect(&comPort, &QSerialPort::readyRead , this, &CommUART::DataReceived);
    QObject::connect(&comPort, &QSerialPort::errorOccurred, this, &CommUART::ErrorReporByLL_Driver);
    GetComPortSettings(port, baudrate);
    comPort.setPortName(port);
    comPort.setBaudRate(baudrate);
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

