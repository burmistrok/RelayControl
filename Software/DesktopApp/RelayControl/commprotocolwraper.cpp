#include "commprotocolwraper.h"

#define SET_CMD             0xAA
#define READ_ACT_STS_BYTE1  0x06
#define READ_ACT_STS_BYTE2  0x53
#define READ_ACT_STS_BYTE3  0x54

CommProtocolWraper::CommProtocolWraper(QObject *parent) : QObject(parent)
{
    serialcommWraper = new CommUART;
    QObject::connect(serialcommWraper, &CommUART::ReportErrorToDriver, this, &CommProtocolWraper::ReportError);
}
void CommProtocolWraper::processMsgs(void)
{
    QByteArray Data = nullptr;

    if( eProcessData == commProtoState )
    {
        if( ((uint8_t)this->receivedData[3]) == ComWrpClcCrc(receivedData))
        {
            Data.append(this->receivedData[1]);
            Data.append(this->receivedData[2]);
            emit DataReceived(Data);
            Data.clear();
        }
        this->receivedData.clear();
        commProtoState = eWaitCmd;
    }

    if (false != serialcommWraper->GetData( &Data))
    {
        this->delayBtwData = 0u;
        switch (commProtoState)
        {
        case eWaitCmd:
            if(IsSupportedCmd(Data))
            {
                if( 3 <= Data.size() )
                {
                    commProtoState = eProcessData;
                }
                else
                {
                    commProtoState = eWaitData;
                }
                this->receivedData = Data;

            }
            break;

        case eWaitData:
            this->receivedData.append(Data);
            if( 3 <= Data.size() )
            {
                commProtoState = eProcessData;
            }
            break;

        default:
            ErrorHandler();

        }
    }
    else
    {
        if ( MAX_MSG_DELAY <= this->delayBtwData)
        {
            this->delayBtwData = 0u;
            commProtoState = eWaitCmd;
            this->receivedData.clear();
        }
        else
        {
            this->delayBtwData++;
        }

    }

}

uint8_t CommProtocolWraper::ComWrpClcCrc(QByteArray msg)
{
    QByteArray resultQBA;

    resultQBA.append( msg.at(0) ^ msg.at(1) ^ msg.at(2));

    uint8_t result = resultQBA[0];
    return result;
}

bool CommProtocolWraper::IsSupportedCmd(QByteArray data )
{
    bool result = false;
    if(!data.isEmpty())
    {
        if(((char)SET_CMD == data[0])||( (char)READ_ACT_STS_BYTE1 == data[0]))
        {
            result = true;
        }
    }

    return result;
}

void CommProtocolWraper::ErrorHandler()
{
    emit ReportErrorToApp("Err", "Something Wrong");
}


void CommProtocolWraper::WriteDataToDevice(int request,ComandFormant Msg)
{
    QByteArray msg;

    switch (request) {

    case CommProtocolWraper::e_SetActuatorsState:;
        msg.append(SET_CMD);
        msg.append((Msg & 0xFF00) >> BYTE_BITS);
        msg.append(Msg & 0x00FF);
        msg.append( ComWrpClcCrc(msg));
        this->serialcommWraper->WriteData(msg);
        break;

    case CommProtocolWraper::e_CheckActualState:

        msg.append(READ_ACT_STS_BYTE1);
        msg.append(READ_ACT_STS_BYTE2);
        msg.append(READ_ACT_STS_BYTE3);
        msg.append( ComWrpClcCrc(msg));
        this->serialcommWraper->WriteData(msg);
        break;

    }
}

void CommProtocolWraper::CheckConection(void)
{
    this->serialcommWraper->IsConnected();
}

void CommProtocolWraper::ReportError(QString status, QString Data)
{
    emit ReportErrorToApp(status, Data);
}
