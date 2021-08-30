#ifndef COMMUARTWRAPER_H
#define COMMUARTWRAPER_H

#include <QObject>
#include <QSerialPort>

class CommUARTWraper: public QSerialPort
{
    Q_OBJECT

private:
    QSerialPort comPort;
    QString RxBuffer;


public:
    CommUARTWraper();
    ~CommUARTWraper();
    void IsConnected(void);

signals:
    void ReportError(QString status, QString Data);


public slots:
    void WriteData(QString Data);
    void DataReceived(void);
    bool GetData(QString* Data);


};

#endif // COMMUARTWRAPER_H
