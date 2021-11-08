/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RelayControl/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[36];
    char stringdata0[736];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "SendCmdToDevice"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "signal"
QT_MOC_LITERAL(4, 35, 3), // "msg"
QT_MOC_LITERAL(5, 39, 12), // "AppWillClose"
QT_MOC_LITERAL(6, 52, 8), // "SaveData"
QT_MOC_LITERAL(7, 61, 6), // "msgLst"
QT_MOC_LITERAL(8, 68, 10), // "ReporError"
QT_MOC_LITERAL(9, 79, 6), // "status"
QT_MOC_LITERAL(10, 86, 3), // "Msg"
QT_MOC_LITERAL(11, 90, 21), // "QMessageBoxCloseEvent"
QT_MOC_LITERAL(12, 112, 9), // "GetStatus"
QT_MOC_LITERAL(13, 122, 3), // "sts"
QT_MOC_LITERAL(14, 126, 18), // "SetInitActuatorMsg"
QT_MOC_LITERAL(15, 145, 27), // "on_turnOffAllButton_clicked"
QT_MOC_LITERAL(16, 173, 37), // "on_comboBoxErr1_1_currentInde..."
QT_MOC_LITERAL(17, 211, 4), // "arg1"
QT_MOC_LITERAL(18, 216, 26), // "on_actionConnect_triggered"
QT_MOC_LITERAL(19, 243, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(20, 267, 20), // "on_UpdBoxSts_toggled"
QT_MOC_LITERAL(21, 288, 7), // "checked"
QT_MOC_LITERAL(22, 296, 21), // "on_BoxDebuger_toggled"
QT_MOC_LITERAL(23, 318, 18), // "on_BoxKL15_toggled"
QT_MOC_LITERAL(24, 337, 18), // "on_BoxKL56_toggled"
QT_MOC_LITERAL(25, 356, 27), // "on_setInitStsButton_clicked"
QT_MOC_LITERAL(26, 384, 24), // "on_OnlyDbgButton_clicked"
QT_MOC_LITERAL(27, 409, 37), // "on_comboBoxErr1_2_currentInde..."
QT_MOC_LITERAL(28, 447, 37), // "on_comboBoxErr1_3_currentInde..."
QT_MOC_LITERAL(29, 485, 37), // "on_comboBoxErr1_4_currentInde..."
QT_MOC_LITERAL(30, 523, 37), // "on_comboBoxErr2_1_currentInde..."
QT_MOC_LITERAL(31, 561, 37), // "on_comboBoxErr2_2_currentInde..."
QT_MOC_LITERAL(32, 599, 37), // "on_comboBoxErr2_3_currentInde..."
QT_MOC_LITERAL(33, 637, 37), // "on_comboBoxErr2_4_currentInde..."
QT_MOC_LITERAL(34, 675, 22), // "on_SendUpdates_clicked"
QT_MOC_LITERAL(35, 698, 37) // "on_comboBoxErr1_5_currentInde..."

    },
    "MainWindow\0SendCmdToDevice\0\0signal\0"
    "msg\0AppWillClose\0SaveData\0msgLst\0"
    "ReporError\0status\0Msg\0QMessageBoxCloseEvent\0"
    "GetStatus\0sts\0SetInitActuatorMsg\0"
    "on_turnOffAllButton_clicked\0"
    "on_comboBoxErr1_1_currentIndexChanged\0"
    "arg1\0on_actionConnect_triggered\0"
    "on_actionSave_triggered\0on_UpdBoxSts_toggled\0"
    "checked\0on_BoxDebuger_toggled\0"
    "on_BoxKL15_toggled\0on_BoxKL56_toggled\0"
    "on_setInitStsButton_clicked\0"
    "on_OnlyDbgButton_clicked\0"
    "on_comboBoxErr1_2_currentIndexChanged\0"
    "on_comboBoxErr1_3_currentIndexChanged\0"
    "on_comboBoxErr1_4_currentIndexChanged\0"
    "on_comboBoxErr2_1_currentIndexChanged\0"
    "on_comboBoxErr2_2_currentIndexChanged\0"
    "on_comboBoxErr2_3_currentIndexChanged\0"
    "on_comboBoxErr2_4_currentIndexChanged\0"
    "on_SendUpdates_clicked\0"
    "on_comboBoxErr1_5_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  144,    2, 0x06 /* Public */,
       5,    0,  149,    2, 0x06 /* Public */,
       6,    1,  150,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,  153,    2, 0x0a /* Public */,
      11,    0,  158,    2, 0x0a /* Public */,
      12,    2,  159,    2, 0x0a /* Public */,
      14,    1,  164,    2, 0x0a /* Public */,
      15,    0,  167,    2, 0x08 /* Private */,
      16,    1,  168,    2, 0x08 /* Private */,
      18,    0,  171,    2, 0x08 /* Private */,
      19,    0,  172,    2, 0x08 /* Private */,
      20,    1,  173,    2, 0x08 /* Private */,
      22,    1,  176,    2, 0x08 /* Private */,
      23,    1,  179,    2, 0x08 /* Private */,
      24,    1,  182,    2, 0x08 /* Private */,
      25,    0,  185,    2, 0x08 /* Private */,
      26,    0,  186,    2, 0x08 /* Private */,
      27,    1,  187,    2, 0x08 /* Private */,
      28,    1,  190,    2, 0x08 /* Private */,
      29,    1,  193,    2, 0x08 /* Private */,
      30,    1,  196,    2, 0x08 /* Private */,
      31,    1,  199,    2, 0x08 /* Private */,
      32,    1,  202,    2, 0x08 /* Private */,
      33,    1,  205,    2, 0x08 /* Private */,
      34,    0,  208,    2, 0x08 /* Private */,
      35,    1,  209,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,   13,
    QMetaType::Void, QMetaType::QStringList,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendCmdToDevice((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->AppWillClose(); break;
        case 2: _t->SaveData((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: _t->ReporError((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->QMessageBoxCloseEvent(); break;
        case 5: _t->GetStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->SetInitActuatorMsg((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 7: _t->on_turnOffAllButton_clicked(); break;
        case 8: _t->on_comboBoxErr1_1_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_actionConnect_triggered(); break;
        case 10: _t->on_actionSave_triggered(); break;
        case 11: _t->on_UpdBoxSts_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_BoxDebuger_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_BoxKL15_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_BoxKL56_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_setInitStsButton_clicked(); break;
        case 16: _t->on_OnlyDbgButton_clicked(); break;
        case 17: _t->on_comboBoxErr1_2_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->on_comboBoxErr1_3_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->on_comboBoxErr1_4_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->on_comboBoxErr2_1_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->on_comboBoxErr2_2_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->on_comboBoxErr2_3_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->on_comboBoxErr2_4_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: _t->on_SendUpdates_clicked(); break;
        case 25: _t->on_comboBoxErr1_5_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendCmdToDevice)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::AppWillClose)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SaveData)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::SendCmdToDevice(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::AppWillClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::SaveData(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
