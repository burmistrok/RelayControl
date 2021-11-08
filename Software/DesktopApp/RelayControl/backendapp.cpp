#include "backendapp.h"

#include <QThread>
#include <QFile>
#include "commondata.h"


#define BOUND_OF_MSG "\n////////\n"

#define SET_BIT_MASK(arg, mask)  (arg|=mask)
#define RESET_BIT_MASK(arg, mask)  (arg&=(~mask))

#define KL15_BIT        0x0001
#define KL56_BIT        0x0002
#define STS_ADV_ERR1    0x0004
#define STS_ADV_ERR2    0x0008
#define STS_ADV_ERR3    0x0010
#define STS_ADV_ERR4    0x0020
#define SWT_ADV_ERR1    0x0040
#define SWT_ADV_ERR2    0x0080
#define ONLY_DBG_BIT    0x0100
#define SWT_ADV_ERR3    0x0200
#define SWT_ADV_ERR4    0x0400
#define STS_SMP_ERR1    0x0800
#define STS_SMP_ERR2    0x1000
#define STS_SMP_ERR3    0x2000
#define STS_SMP_ERR4    0x4000
#define STS_SMP_ERR5    0x8000

#define MAX_ACK_DELAY (5000u/TASK_RECURRENCE)



BackEndApp::BackEndApp(QObject *parent) : QObject(parent)
{

    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &BackEndApp::BackEndAppThread);
    this->timer->start(TASK_RECURRENCE);
    CommandBitField = 0u;
    isAckReceived = true;
    u16_AckDelay = 0u;
}

void BackEndApp::start(void)
{
    QStringList actMsgList;
    CommVar = new CommProtocolWraper;
    QObject::connect( this->CommVar, &CommProtocolWraper::DataReceived, this, &BackEndApp::DataReceived );
    QObject::connect( this->CommVar, &CommProtocolWraper::ReportErrorToApp, this, &BackEndApp::ReportErrorFromComm );
    QObject::connect( this, &BackEndApp::CheckConectionToLLDriver, this->CommVar, &CommProtocolWraper::CheckConection );
    qRegisterMetaType<ComandFormant>("ComandFormant");
    QObject::connect( this, &BackEndApp::WriteDataToDeviceToLLDriver, this->CommVar, &CommProtocolWraper::WriteDataToDevice );
    emit CheckConectionToLLDriver();
    GetMsgForActuators(actMsgList);
    emit InstalInitActuatorMsg(actMsgList);
    emit WriteDataToDeviceToLLDriver( CommProtocolWraper::e_CheckActualState, 0 );
}

void BackEndApp::GetMsgForActuators(QStringList &msgList)
{
    QFile fileMsg("ActutorDescriptions.txt");
    QString boundMsg = BOUND_OF_MSG;

    boundMsg.remove("\n");

    if(fileMsg.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream textFile(&fileMsg);
        while(!textFile.atEnd())
        {
            QString actMsg;
            QString tempBuffer;
            do{
                tempBuffer.clear();
                if(!textFile.atEnd())
                {
                    tempBuffer = textFile.readLine();
                    if(boundMsg != tempBuffer)
                    {
                        actMsg.append(tempBuffer);
                        actMsg.append("\n");
                    }
                }
            }
            while(boundMsg != tempBuffer);

            if(boundMsg == actMsg)
            {
                continue;
            }
            else
            {

            }
            msgList.push_back(actMsg);
            actMsg.clear();

        }
    }
    else
    {
        msgList.push_back("/* Write here description for error */");
        msgList.push_back("/* Write here description for error */");
        msgList.push_back("/* Write here description for error */");
        msgList.push_back("/* Write here description for error */");
        msgList.push_back("/* Write here description for error */");
        msgList.push_back("/* Write here description for error */");
        msgList.push_back("/* Write here description for error */");
        msgList.push_back("/* Write here description for error */");
        msgList.push_back("/* Write here description for error */");
    }
}

void BackEndApp::BackEndAppThread(void)
{
    this->CommVar->processMsgs();

    if( false == isAckReceived)
    {
        if(MAX_ACK_DELAY <= u16_AckDelay)
        {
            emit WriteDataToDeviceToLLDriver( CommProtocolWraper::e_SetActuatorsState, CommandBitField );
            u16_AckDelay = 0u;
        }
        else
        {
            u16_AckDelay++;
        }
    }

}

void BackEndApp::AppWillCloseNotify()
{
    this->timer->~QTimer();
}

void BackEndApp::SaveMsgFromTextBox(QStringList msgLst)
{
    QString actualMsg;
    QFile fileMsg("ActutorDescriptions.txt");
    QByteArray qArray;

    if(fileMsg.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        for (int i=0; i < msgLst.size(); i++)
        {
            actualMsg.append(msgLst.at(i));
            actualMsg.append(BOUND_OF_MSG);
            qArray = actualMsg.toUtf8();
            fileMsg.write(qArray);
            qDebug()  << actualMsg;
            actualMsg.clear();
        }
        fileMsg.close();
    }



}


void BackEndApp::GetCmdToDevice(int signal, int msg)
{
    switch(signal)
    {
    case CommonData::SetInitState:
    case CommonData::SimpleRelay1:
    case CommonData::SimpleRelay2:
    case CommonData::SimpleRelay3:
    case CommonData::SimpleRelay4:
    case CommonData::SimpleRelay5:
    case CommonData::AdvanceRelay1:
    case CommonData::AdvanceRelay2:
    case CommonData::AdvanceRelay3:
    case CommonData::AdvanceRelay4:
    case CommonData::Kl56State:
    case CommonData::Kl15State:
    case CommonData::OnlyDbg:
    case CommonData::DbgState:
    case CommonData::TurnOffAll:
        ProcessCmd(signal, msg);
        break;

    case CommonData::GroupSts:
        if(CommonData::ON == msg)
        {
            isOneClickActive = true;
        }
        else
        {
            isOneClickActive = false;
        }
        break;

    case CommonData::SetAllSignals:
        if(false != isOneClickActive)
        {
            emit WriteDataToDeviceToLLDriver( CommProtocolWraper::e_SetActuatorsState, CommandBitField );
            u16_AckDelay = 0u;
            isAckReceived = false;
        }
        break;

    default:
        qDebug() << "Error\nNo such actuator";
    }

    if(false == isOneClickActive)
    {
        if(CommonData::GroupSts != signal)
        {
            emit WriteDataToDeviceToLLDriver( CommProtocolWraper::e_SetActuatorsState, CommandBitField );
            u16_AckDelay = 0u;
            isAckReceived = false;
        }
    }

}

void BackEndApp::ReportErrorFromComm(QString status, QString Data)
{
    emit this->ReportError(status, Data);
}

void BackEndApp::DataReceived(QByteArray Msg)
{
    ComandFormant data = 0u;
    data = Msg[0];
    data = data << BYTE_BITS;
    data |= Msg[1];
    CommandBitField = data;
    this->ProcessReceivedData(data);
    u16_AckDelay = 0u;
    isAckReceived = true;
}

BackEndApp::~BackEndApp()
{
    if (NULL != CommVar)
    {
        delete CommVar;
    }
}

void BackEndApp::ProcessCmd(int signal, int msg)
{
    ComandFormant &data = CommandBitField;
    switch(signal)
    {
    case CommonData::SimpleRelay1:
        SetRelayVal(data, msg, STS_SMP_ERR1 );
        break;
    case CommonData::SimpleRelay2:
        SetRelayVal(data, msg, STS_SMP_ERR2 );
        break;
    case CommonData::SimpleRelay3:
        SetRelayVal(data, msg, STS_SMP_ERR3 );
        break;
    case CommonData::SimpleRelay4:
        SetRelayVal(data, msg, STS_SMP_ERR4 );
        break;
    case CommonData::SimpleRelay5:
        SetRelayVal(data, msg, STS_SMP_ERR5 );
        break;

    case CommonData::DbgState:
        SetRelayVal(data, msg, ONLY_DBG_BIT);
        break;

    case CommonData::AdvanceRelay1:
        SetRelayVal(data, msg, STS_ADV_ERR1, SWT_ADV_ERR1 );
        break;
    case CommonData::AdvanceRelay2:
        SetRelayVal(data, msg, STS_ADV_ERR2, SWT_ADV_ERR2 );
        break;
    case CommonData::AdvanceRelay3:
        SetRelayVal(data, msg, STS_ADV_ERR3, SWT_ADV_ERR3 );
        break;
    case CommonData::AdvanceRelay4:
        SetRelayVal(data, msg, STS_ADV_ERR4, SWT_ADV_ERR4 );
        break;

    case CommonData::Kl56State:
        SetRelayVal(data, msg, KL56_BIT);
        break;
    case CommonData::Kl15State:
        SetRelayVal(data, msg, KL15_BIT);
        break;
    case CommonData::TurnOffAll:
        data = 0;
        break;
    case CommonData::OnlyDbg:
        data = ONLY_DBG_BIT;
        break;
    case CommonData::SetInitState:
        data = ONLY_DBG_BIT | KL15_BIT | KL56_BIT;
        break;

    default:
        qDebug()  << "Error";
    }
}

void BackEndApp::SetRelayVal(ComandFormant &data, int msg, ComandFormant mask)
{
    if(CommonData::ON == msg)
    {
        SET_BIT_MASK(data,mask);
    }
    else
    {
        RESET_BIT_MASK(data,mask);
    }
}

void BackEndApp::SetRelayVal(ComandFormant &data, int msg, ComandFormant mask1, ComandFormant mask2)
{
    if(CommonData::Normal == msg)
    {
        RESET_BIT_MASK(data,mask1);
        RESET_BIT_MASK(data,mask2);
    }
    else
    {
        SET_BIT_MASK(data,mask1);
        if(CommonData::ShToBat == msg)
        {
            SET_BIT_MASK(data,mask2);
        }
        else if (CommonData::ShToGnd == msg)
        {
            RESET_BIT_MASK(data,mask2);
        }
    }
}

void BackEndApp::ProcessReceivedData(ComandFormant data)
{
    this->CheckRelayVal(data, CommonData::DbgState,  ONLY_DBG_BIT);
    this->CheckRelayVal(data, CommonData::Kl15State, KL15_BIT);
    this->CheckRelayVal(data, CommonData::Kl56State, KL56_BIT);

    this->CheckRelayVal(data, CommonData::SimpleRelay1, STS_SMP_ERR1);
    this->CheckRelayVal(data, CommonData::SimpleRelay2, STS_SMP_ERR2);
    this->CheckRelayVal(data, CommonData::SimpleRelay3, STS_SMP_ERR3);
    this->CheckRelayVal(data, CommonData::SimpleRelay4, STS_SMP_ERR4);
    this->CheckRelayVal(data, CommonData::SimpleRelay5, STS_SMP_ERR5);

    this->CheckRelayVal(data, CommonData::AdvanceRelay1, STS_ADV_ERR1, SWT_ADV_ERR1);
    this->CheckRelayVal(data, CommonData::AdvanceRelay2, STS_ADV_ERR2, SWT_ADV_ERR2);
    this->CheckRelayVal(data, CommonData::AdvanceRelay3, STS_ADV_ERR3, SWT_ADV_ERR3);
    this->CheckRelayVal(data, CommonData::AdvanceRelay4, STS_ADV_ERR4, SWT_ADV_ERR4);

}

void BackEndApp::CheckRelayVal(ComandFormant data, int msg, ComandFormant mask)
{
    if (mask & data)
    {
        emit this->ShowStatus(msg, CommonData::ON);
    }
    else
    {
        emit this->ShowStatus(msg, CommonData::OFF);
    }
}

void BackEndApp::CheckRelayVal(ComandFormant data, int msg, ComandFormant mask1, ComandFormant mask2)
{
    if (mask1 & data)
    {
        if (mask2 & data)
        {
           emit this->ShowStatus(msg, CommonData::ShToBat);
        }
        else
        {
            emit this->ShowStatus(msg, CommonData::ShToGnd);
        }
    }
    else
    {
        emit this->ShowStatus(msg, CommonData::Normal);
    }
}
