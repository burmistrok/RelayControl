#include "commuartwraper.h"
#include <QDebug>

/*Declaration section*/



/*Static variables*/


/*Static functions*/


#if 0
void CommUARTWraper::run()
{

    QByteArray readData = serialPort.readAll();
    const QByteArray writeData = "Hello\n";
    serialPort.write(writeData);
    while(true)
    {
        readData.append(serialPort.readAll());

        //serialPort.write(writeData);
        if (!readData.isEmpty())
        {
            qDebug() << readData;
            readData.clear();
        }

        this->sleep(1);

    }
}
#endif


CommUARTWraper::CommUARTWraper()
{
    qDebug() << "Start";

    comPort.setPortName("COM5");
    comPort.setBaudRate(QSerialPort::Baud9600);
}

CommUARTWraper::~CommUARTWraper()
{
    comPort.close();
}

void CommUARTWraper::WriteData(QString Data)
{
    QByteArray BufferArray = Data.toUtf8();
    comPort.write(BufferArray);
}

void CommUARTWraper::DataReceived(void)
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
        emit ReportError("Error", comPort.errorString());
    }
}

bool CommUARTWraper::GetData(QString* Data)
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

void CommUARTWraper::IsConnected(void)
{
    if(!comPort.open(QIODevice::ReadWrite))
    {
        emit ReportError("Error", comPort.errorString());
    }
    else
    {
        emit ReportError("Information", "ComPort successfully have been opened");
    }
}




