#ifndef COMMUART_H
#define COMMUART_H

#include <QObject>
#include <QSerialPort>

class CommUART: public QObject
{
    Q_OBJECT

private:
    QSerialPort comPort;
    QString RxBuffer;


public:
    CommUART(QObject *parent = nullptr);
    ~CommUART();
    void IsConnected(void);

signals:
    void ReportErrorToDriver(QString status, QString Data);


public slots:
    void WriteData(QString Data);
    void DataReceived(void);
    bool GetData(QString* Data);
    void ErrorReporByLL_Driver(QSerialPort::SerialPortError error);




};

#endif // COMMUART_H
