/****************************************************************************
** Meta object code from reading C++ file 'backendapp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RelayControl/backendapp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backendapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BackEndApp_t {
    QByteArrayData data[23];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BackEndApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BackEndApp_t qt_meta_stringdata_BackEndApp = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BackEndApp"
QT_MOC_LITERAL(1, 11, 11), // "ReportError"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "status"
QT_MOC_LITERAL(4, 31, 4), // "Data"
QT_MOC_LITERAL(5, 36, 10), // "ShowStatus"
QT_MOC_LITERAL(6, 47, 6), // "signal"
QT_MOC_LITERAL(7, 54, 3), // "sts"
QT_MOC_LITERAL(8, 58, 24), // "CheckConectionToLLDriver"
QT_MOC_LITERAL(9, 83, 27), // "WriteDataToDeviceToLLDriver"
QT_MOC_LITERAL(10, 111, 7), // "request"
QT_MOC_LITERAL(11, 119, 13), // "ComandFormant"
QT_MOC_LITERAL(12, 133, 4), // "data"
QT_MOC_LITERAL(13, 138, 21), // "InstalInitActuatorMsg"
QT_MOC_LITERAL(14, 160, 6), // "msgLst"
QT_MOC_LITERAL(15, 167, 14), // "GetCmdToDevice"
QT_MOC_LITERAL(16, 182, 3), // "msg"
QT_MOC_LITERAL(17, 186, 19), // "ReportErrorFromComm"
QT_MOC_LITERAL(18, 206, 12), // "DataReceived"
QT_MOC_LITERAL(19, 219, 3), // "Msg"
QT_MOC_LITERAL(20, 223, 16), // "BackEndAppThread"
QT_MOC_LITERAL(21, 240, 18), // "AppWillCloseNotify"
QT_MOC_LITERAL(22, 259, 18) // "SaveMsgFromTextBox"

    },
    "BackEndApp\0ReportError\0\0status\0Data\0"
    "ShowStatus\0signal\0sts\0CheckConectionToLLDriver\0"
    "WriteDataToDeviceToLLDriver\0request\0"
    "ComandFormant\0data\0InstalInitActuatorMsg\0"
    "msgLst\0GetCmdToDevice\0msg\0ReportErrorFromComm\0"
    "DataReceived\0Msg\0BackEndAppThread\0"
    "AppWillCloseNotify\0SaveMsgFromTextBox"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BackEndApp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    2,   74,    2, 0x06 /* Public */,
       8,    0,   79,    2, 0x06 /* Public */,
       9,    2,   80,    2, 0x06 /* Public */,
      13,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    2,   88,    2, 0x0a /* Public */,
      17,    2,   93,    2, 0x0a /* Public */,
      18,    1,   98,    2, 0x0a /* Public */,
      20,    0,  101,    2, 0x0a /* Public */,
      21,    0,  102,    2, 0x0a /* Public */,
      22,    1,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 11,   10,   12,
    QMetaType::Void, QMetaType::QStringList,   14,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QByteArray,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   14,

       0        // eod
};

void BackEndApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BackEndApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReportError((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->ShowStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->CheckConectionToLLDriver(); break;
        case 3: _t->WriteDataToDeviceToLLDriver((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< ComandFormant(*)>(_a[2]))); break;
        case 4: _t->InstalInitActuatorMsg((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 5: _t->GetCmdToDevice((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->ReportErrorFromComm((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->DataReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->BackEndAppThread(); break;
        case 9: _t->AppWillCloseNotify(); break;
        case 10: _t->SaveMsgFromTextBox((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BackEndApp::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEndApp::ReportError)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BackEndApp::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEndApp::ShowStatus)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BackEndApp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEndApp::CheckConectionToLLDriver)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BackEndApp::*)(int , ComandFormant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEndApp::WriteDataToDeviceToLLDriver)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (BackEndApp::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEndApp::InstalInitActuatorMsg)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BackEndApp::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_BackEndApp.data,
    qt_meta_data_BackEndApp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BackEndApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BackEndApp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BackEndApp.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BackEndApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void BackEndApp::ReportError(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BackEndApp::ShowStatus(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BackEndApp::CheckConectionToLLDriver()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BackEndApp::WriteDataToDeviceToLLDriver(int _t1, ComandFormant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BackEndApp::InstalInitActuatorMsg(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
