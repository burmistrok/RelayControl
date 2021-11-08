#ifndef COMMPROTOCOLWRAPER_H
#define COMMPROTOCOLWRAPER_H
#include <QObject>
#include "Std_Types.h"
#include "commuart.h"
#include "CommProtocol_Type.h"

class CommProtocolWraper : public QObject
{
    Q_OBJECT
public:
    enum E_SupportedCmd
    {
        e_SetActuatorsState,
        e_CheckActualState
    };
    Q_ENUM(E_SupportedCmd);
    explicit CommProtocolWraper(QObject *parent = nullptr);
    void processMsgs(void);

private:
    CommUART* serialcommWraper = NULL;
    TE_CommProtoState commProtoState = eWaitCmd;
    uint16_t delayBtwData = 0u;
    QByteArray receivedData;
    uint8_t ComWrpClcCrc( QByteArray msg );
    bool IsSupportedCmd(QByteArray data);

    void ErrorHandler(void);
    void ProcessData(QString Data);

signals:
    void ReportErrorToApp(QString status, QString Data);
    void DataReceived(QByteArray Msg);


public slots:
    void ReportError(QString status, QString Data);
    void CheckConection(void);
    void WriteDataToDevice(int request, ComandFormant Msg);


};

#endif // COMMPROTOCOLWRAPER_H
