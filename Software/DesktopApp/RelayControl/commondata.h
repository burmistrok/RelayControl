#ifndef COMMONDATA_H
#define COMMONDATA_H

#include <QObject>
#include "Std_Types.h"

class CommonData : public QObject
{
    Q_OBJECT
public:
    explicit CommonData(QObject *parent = nullptr);
    enum E_SignalEnum
    {
        Err = 0u,
        Save,
        ConnectCom,
        DbgState,
        Kl15State,
        Kl56State,
        SetInitState,
        OnlyDbg,
        TurnOffAll,
        SimpleRelay1,
        SimpleRelay2,
        SimpleRelay3,
        SimpleRelay4,
        SimpleRelay5,
        AdvanceRelay1,
        AdvanceRelay2,
        AdvanceRelay3,
        AdvanceRelay4,
        GroupSts,
        SetAllSignals,


        /*Mark of end*/
        EndOfSignals

    };
    Q_ENUM(E_SignalEnum);

    enum E_BoxSts
    {
        OFF = 0,
        ON
    };
    Q_ENUM(E_BoxSts);
    enum E_AdvanceComboBoxSts
    {
        Normal = 0,
        ShToBat,
        ShToGnd
    };
    Q_ENUM(E_AdvanceComboBoxSts);

signals:

};

#endif // COMMONDATA_H
