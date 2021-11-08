#ifndef COMMPROTOCOL_TYPE_H
#define COMMPROTOCOL_TYPE_H




#define MAX_MSG_DELAY (200u/TASK_RECURRENCE)

typedef enum
{
    eWaitCmd = 0u,
    eWaitData,
    eProcessData,
    eErrorHandler

}TE_CommProtoState;



#endif // COMMPROTOCOL_TYPE_H
