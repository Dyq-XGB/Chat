/****************************************************************************
** Meta object code from reading C++ file 'connecttoserver.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../connecttoserver.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connecttoserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSConnectToServerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSConnectToServerENDCLASS = QtMocHelpers::stringData(
    "ConnectToServer",
    "ConnectFaile",
    "",
    "ConnectSuccess",
    "sendOk",
    "PasureNotgetMessage",
    "bytes",
    "slot_startwork",
    "NeedGetAllInfo",
    "SendAllinfotoServer"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSConnectToServerENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[16];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[7];
    char stringdata5[20];
    char stringdata6[6];
    char stringdata7[15];
    char stringdata8[15];
    char stringdata9[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSConnectToServerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSConnectToServerENDCLASS_t qt_meta_stringdata_CLASSConnectToServerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "ConnectToServer"
        QT_MOC_LITERAL(16, 12),  // "ConnectFaile"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 14),  // "ConnectSuccess"
        QT_MOC_LITERAL(45, 6),  // "sendOk"
        QT_MOC_LITERAL(52, 19),  // "PasureNotgetMessage"
        QT_MOC_LITERAL(72, 5),  // "bytes"
        QT_MOC_LITERAL(78, 14),  // "slot_startwork"
        QT_MOC_LITERAL(93, 14),  // "NeedGetAllInfo"
        QT_MOC_LITERAL(108, 19)   // "SendAllinfotoServer"
    },
    "ConnectToServer",
    "ConnectFaile",
    "",
    "ConnectSuccess",
    "sendOk",
    "PasureNotgetMessage",
    "bytes",
    "slot_startwork",
    "NeedGetAllInfo",
    "SendAllinfotoServer"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSConnectToServerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,
       4,    0,   52,    2, 0x06,    3 /* Public */,
       5,    1,   53,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,   56,    2, 0x0a,    6 /* Public */,
       9,    0,   59,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ConnectToServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSConnectToServerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSConnectToServerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSConnectToServerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ConnectToServer, std::true_type>,
        // method 'ConnectFaile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ConnectSuccess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendOk'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'PasureNotgetMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'slot_startwork'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'SendAllinfotoServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ConnectToServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConnectToServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ConnectFaile(); break;
        case 1: _t->ConnectSuccess(); break;
        case 2: _t->sendOk(); break;
        case 3: _t->PasureNotgetMessage((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 4: _t->slot_startwork((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->SendAllinfotoServer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConnectToServer::*)();
            if (_t _q_method = &ConnectToServer::ConnectFaile; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ConnectToServer::*)();
            if (_t _q_method = &ConnectToServer::ConnectSuccess; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ConnectToServer::*)();
            if (_t _q_method = &ConnectToServer::sendOk; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ConnectToServer::*)(QByteArray );
            if (_t _q_method = &ConnectToServer::PasureNotgetMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *ConnectToServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConnectToServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSConnectToServerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ConnectToServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ConnectToServer::ConnectFaile()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ConnectToServer::ConnectSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ConnectToServer::sendOk()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ConnectToServer::PasureNotgetMessage(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
