/****************************************************************************
** Meta object code from reading C++ file 'commprotocolwraper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RelayControl/commprotocolwraper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commprotocolwraper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CommProtocolWraper_t {
    QByteArrayData data[15];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommProtocolWraper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommProtocolWraper_t qt_meta_stringdata_CommProtocolWraper = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CommProtocolWraper"
QT_MOC_LITERAL(1, 19, 16), // "ReportErrorToApp"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 6), // "status"
QT_MOC_LITERAL(4, 44, 4), // "Data"
QT_MOC_LITERAL(5, 49, 12), // "DataReceived"
QT_MOC_LITERAL(6, 62, 3), // "Msg"
QT_MOC_LITERAL(7, 66, 11), // "ReportError"
QT_MOC_LITERAL(8, 78, 14), // "CheckConection"
QT_MOC_LITERAL(9, 93, 17), // "WriteDataToDevice"
QT_MOC_LITERAL(10, 111, 7), // "request"
QT_MOC_LITERAL(11, 119, 13), // "ComandFormant"
QT_MOC_LITERAL(12, 133, 14), // "E_SupportedCmd"
QT_MOC_LITERAL(13, 148, 19), // "e_SetActuatorsState"
QT_MOC_LITERAL(14, 168, 18) // "e_CheckActualState"

    },
    "CommProtocolWraper\0ReportErrorToApp\0"
    "\0status\0Data\0DataReceived\0Msg\0ReportError\0"
    "CheckConection\0WriteDataToDevice\0"
    "request\0ComandFormant\0E_SupportedCmd\0"
    "e_SetActuatorsState\0e_CheckActualState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommProtocolWraper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       1,   58, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   47,    2, 0x0a /* Public */,
       8,    0,   52,    2, 0x0a /* Public */,
       9,    2,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QByteArray,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 11,   10,    6,

 // enums: name, alias, flags, count, data
      12,   12, 0x0,    2,   63,

 // enum data: key, value
      13, uint(CommProtocolWraper::e_SetActuatorsState),
      14, uint(CommProtocolWraper::e_CheckActualState),

       0        // eod
};

void CommProtocolWraper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommProtocolWraper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReportErrorToApp((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->DataReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->ReportError((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->CheckConection(); break;
        case 4: _t->WriteDataToDevice((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< ComandFormant(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CommProtocolWraper::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommProtocolWraper::ReportErrorToApp)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CommProtocolWraper::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommProtocolWraper::DataReceived)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CommProtocolWraper::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CommProtocolWraper.data,
    qt_meta_data_CommProtocolWraper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CommProtocolWraper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommProtocolWraper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CommProtocolWraper.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CommProtocolWraper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CommProtocolWraper::ReportErrorToApp(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CommProtocolWraper::DataReceived(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
