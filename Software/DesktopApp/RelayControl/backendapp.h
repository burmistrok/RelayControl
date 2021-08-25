#ifndef BACKENDAPP_H
#define BACKENDAPP_H

#include <QObject>
#include <QThread>

class BackEndApp : public QThread
{
    Q_OBJECT
public:
    explicit BackEndApp();

    void run(void);

signals:
    void CheckDataFromCommPort(void);

};

#endif // BACKENDAPP_H
