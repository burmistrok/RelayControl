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
    bool isAckReceived;
    uint16_t u16_AckDelay;
    CommProtocolWraper* CommVar = NULL;
    QTimer *timer;
    void GetMsgForActuators(QStringList& msgList);
    bool isOneClickActive = false;
    ComandFormant CommandBitField;
    void ProcessCmd(int signal, int msg);
    void SetRelayVal(ComandFormant& data, int msg, ComandFormant mask);
    void SetRelayVal(ComandFormant& data, int msg, ComandFormant mask1, ComandFormant mask2);
    void ProcessReceivedData(ComandFormant data);
    void CheckRelayVal(ComandFormant data, int msg, ComandFormant mask);
    void CheckRelayVal(ComandFormant data, int msg, ComandFormant mask1, ComandFormant mask2);


signals:
    void ReportError(QString status, QString Data);
    void ShowStatus(int signal, int sts);
    void CheckConectionToLLDriver(void);
    void WriteDataToDeviceToLLDriver(int request, ComandFormant data);
    void InstalInitActuatorMsg(QStringList msgLst);

public slots:
    void GetCmdToDevice(int signal, int msg);
    void ReportErrorFromComm(QString status, QString Data);
    void DataReceived(QByteArray Msg);
    void BackEndAppThread(void);
    void AppWillCloseNotify(void);
    void SaveMsgFromTextBox(QStringList msgLst);

};

#endif // BACKENDAPP_H
