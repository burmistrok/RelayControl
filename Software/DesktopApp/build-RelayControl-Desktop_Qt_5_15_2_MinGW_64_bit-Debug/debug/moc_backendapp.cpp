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
    QByteArrayData data[13];
    char stringdata0[169];
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
QT_MOC_LITERAL(6, 47, 3), // "Msg"
QT_MOC_LITERAL(7, 51, 24), // "CheckConectionToLLDriver"
QT_MOC_LITERAL(8, 76, 27), // "WriteDataToDeviceToLLDriver"
QT_MOC_LITERAL(9, 104, 14), // "GetCmdToDevice"
QT_MOC_LITERAL(10, 119, 19), // "ReportErrorFromComm"
QT_MOC_LITERAL(11, 139, 12), // "DataReceived"
QT_MOC_LITERAL(12, 152, 16) // "BackEndAppThread"

    },
    "BackEndApp\0ReportError\0\0status\0Data\0"
    "ShowStatus\0Msg\0CheckConectionToLLDriver\0"
    "WriteDataToDeviceToLLDriver\0GetCmdToDevice\0"
    "ReportErrorFromComm\0DataReceived\0"
    "BackEndAppThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BackEndApp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       5,    1,   59,    2, 0x06 /* Public */,
       7,    0,   62,    2, 0x06 /* Public */,
       8,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   66,    2, 0x0a /* Public */,
      10,    2,   69,    2, 0x0a /* Public */,
      11,    1,   74,    2, 0x0a /* Public */,
      12,    0,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void BackEndApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BackEndApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReportError((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->ShowStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->CheckConectionToLLDriver(); break;
        case 3: _t->WriteDataToDeviceToLLDriver((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->GetCmdToDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->ReportErrorFromComm((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->DataReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->BackEndAppThread(); break;
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
            using _t = void (BackEndApp::*)(QString );
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
            using _t = void (BackEndApp::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEndApp::WriteDataToDeviceToLLDriver)) {
                *result = 3;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
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
void BackEndApp::ShowStatus(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BackEndApp::CheckConectionToLLDriver()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BackEndApp::WriteDataToDeviceToLLDriver(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
