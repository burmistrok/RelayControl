#ifndef BACKENDAPP_H
#define BACKENDAPP_H

#include <QObject>
#include "Std_Types.h"
#include "commprotocolwraper.h"
#include <QTimer>

class BackEndApp : public QObject
{
    Q_OBJECT
public:
    explicit BackEndApp(QObject *parent = nullptr);
    ~BackEndApp();
    void start(void);

private:
    CommProtocolWraper* CommVar = NULL;
    QTimer *timer;

signals:
    void ReportError(QString status, QString Data);
    void ShowStatus(QString Msg);
    void CheckConectionToLLDriver(void);
    void WriteDataToDeviceToLLDriver(QString Msg);

public slots:
    void GetCmdToDevice(QString Msg);
    void ReportErrorFromComm(QString status, QString Data);
    void DataReceived(QString Msg);
    void BackEndAppThread(void);

};

#endif // BACKENDAPP_H
