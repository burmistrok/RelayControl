#ifndef COMMPROTOCOLWRAPER_H
#define COMMPROTOCOLWRAPER_H
#include <QObject>
#include "Std_Types.h"
#include "commuart.h"

class CommProtocolWraper : public QObject
{
    Q_OBJECT
public:
    explicit CommProtocolWraper(QObject *parent = nullptr);
    void processMsgs(void);

private:
    CommUART* serialcommWraper = NULL;

signals:
    void ReportErrorToApp(QString status, QString Data);
    void DataRecieved(QString Msg);


public slots:
    void ReportError(QString status, QString Data);
    void CheckConection(void);
    void WriteDataToDevice(QString Msg);


};

#endif // COMMPROTOCOLWRAPER_H
