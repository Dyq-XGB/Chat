/****************************************************************************
** Meta object code from reading C++ file 'pasuremessage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client2/pasuremessage.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pasuremessage.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSPasureMessageENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPasureMessageENDCLASS = QtMocHelpers::stringData(
    "PasureMessage",
    "aMessage",
    "",
    "friendid",
    "message",
    "time",
    "aPixmap",
    "pixsavepath",
    "aFile",
    "key",
    "filesize",
    "filename",
    "isFindfriendReslute",
    "array",
    "isaAddfriendrequest",
    "friendname",
    "pixpath",
    "isaAddfriendanswer",
    "isNeedGetAllInfo",
    "answer",
    "TheMessageitem",
    "TheFrienditem",
    "TheBaseInfo",
    "TheOtherRequestAdd",
    "sendaMessage",
    "SaveAllinfoOk",
    "PasureaMessage",
    "bytes",
    "PasureasendMessage",
    "toid",
    "PrepareAllinfo",
    "PasureNotgetmessage",
    "PasureanotGetmessage"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPasureMessageENDCLASS_t {
    uint offsetsAndSizes[66];
    char stringdata0[14];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[8];
    char stringdata5[5];
    char stringdata6[8];
    char stringdata7[12];
    char stringdata8[6];
    char stringdata9[4];
    char stringdata10[9];
    char stringdata11[9];
    char stringdata12[20];
    char stringdata13[6];
    char stringdata14[20];
    char stringdata15[11];
    char stringdata16[8];
    char stringdata17[19];
    char stringdata18[17];
    char stringdata19[7];
    char stringdata20[15];
    char stringdata21[14];
    char stringdata22[12];
    char stringdata23[19];
    char stringdata24[13];
    char stringdata25[14];
    char stringdata26[15];
    char stringdata27[6];
    char stringdata28[19];
    char stringdata29[5];
    char stringdata30[15];
    char stringdata31[20];
    char stringdata32[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPasureMessageENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPasureMessageENDCLASS_t qt_meta_stringdata_CLASSPasureMessageENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "PasureMessage"
        QT_MOC_LITERAL(14, 8),  // "aMessage"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 8),  // "friendid"
        QT_MOC_LITERAL(33, 7),  // "message"
        QT_MOC_LITERAL(41, 4),  // "time"
        QT_MOC_LITERAL(46, 7),  // "aPixmap"
        QT_MOC_LITERAL(54, 11),  // "pixsavepath"
        QT_MOC_LITERAL(66, 5),  // "aFile"
        QT_MOC_LITERAL(72, 3),  // "key"
        QT_MOC_LITERAL(76, 8),  // "filesize"
        QT_MOC_LITERAL(85, 8),  // "filename"
        QT_MOC_LITERAL(94, 19),  // "isFindfriendReslute"
        QT_MOC_LITERAL(114, 5),  // "array"
        QT_MOC_LITERAL(120, 19),  // "isaAddfriendrequest"
        QT_MOC_LITERAL(140, 10),  // "friendname"
        QT_MOC_LITERAL(151, 7),  // "pixpath"
        QT_MOC_LITERAL(159, 18),  // "isaAddfriendanswer"
        QT_MOC_LITERAL(178, 16),  // "isNeedGetAllInfo"
        QT_MOC_LITERAL(195, 6),  // "answer"
        QT_MOC_LITERAL(202, 14),  // "TheMessageitem"
        QT_MOC_LITERAL(217, 13),  // "TheFrienditem"
        QT_MOC_LITERAL(231, 11),  // "TheBaseInfo"
        QT_MOC_LITERAL(243, 18),  // "TheOtherRequestAdd"
        QT_MOC_LITERAL(262, 12),  // "sendaMessage"
        QT_MOC_LITERAL(275, 13),  // "SaveAllinfoOk"
        QT_MOC_LITERAL(289, 14),  // "PasureaMessage"
        QT_MOC_LITERAL(304, 5),  // "bytes"
        QT_MOC_LITERAL(310, 18),  // "PasureasendMessage"
        QT_MOC_LITERAL(329, 4),  // "toid"
        QT_MOC_LITERAL(334, 14),  // "PrepareAllinfo"
        QT_MOC_LITERAL(349, 19),  // "PasureNotgetmessage"
        QT_MOC_LITERAL(369, 20)   // "PasureanotGetmessage"
    },
    "PasureMessage",
    "aMessage",
    "",
    "friendid",
    "message",
    "time",
    "aPixmap",
    "pixsavepath",
    "aFile",
    "key",
    "filesize",
    "filename",
    "isFindfriendReslute",
    "array",
    "isaAddfriendrequest",
    "friendname",
    "pixpath",
    "isaAddfriendanswer",
    "isNeedGetAllInfo",
    "answer",
    "TheMessageitem",
    "TheFrienditem",
    "TheBaseInfo",
    "TheOtherRequestAdd",
    "sendaMessage",
    "SaveAllinfoOk",
    "PasureaMessage",
    "bytes",
    "PasureasendMessage",
    "toid",
    "PrepareAllinfo",
    "PasureNotgetmessage",
    "PasureanotGetmessage"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPasureMessageENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,  122,    2, 0x06,    1 /* Public */,
       6,    3,  129,    2, 0x06,    5 /* Public */,
       8,    5,  136,    2, 0x06,    9 /* Public */,
      12,    1,  147,    2, 0x06,   15 /* Public */,
      14,    4,  150,    2, 0x06,   17 /* Public */,
      17,    4,  159,    2, 0x06,   22 /* Public */,
      18,    1,  168,    2, 0x06,   27 /* Public */,
      20,    0,  171,    2, 0x06,   29 /* Public */,
      21,    0,  172,    2, 0x06,   30 /* Public */,
      22,    0,  173,    2, 0x06,   31 /* Public */,
      23,    0,  174,    2, 0x06,   32 /* Public */,
      24,    1,  175,    2, 0x06,   33 /* Public */,
      25,    0,  178,    2, 0x06,   35 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      26,    1,  179,    2, 0x0a,   36 /* Public */,
      28,    2,  182,    2, 0x0a,   38 /* Public */,
      30,    0,  187,    2, 0x0a,   41 /* Public */,
      31,    1,  188,    2, 0x0a,   42 /* Public */,
      32,    1,  191,    2, 0x0a,   44 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    7,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::QString, QMetaType::QString,    3,    9,   10,   11,    5,
    QMetaType::Void, QMetaType::QJsonArray,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,   15,   16,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,   15,   16,    5,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonArray,   13,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   27,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonArray,   29,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   27,
    QMetaType::Void, QMetaType::QJsonArray,   13,

       0        // eod
};

Q_CONSTINIT const QMetaObject PasureMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSPasureMessageENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPasureMessageENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPasureMessageENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PasureMessage, std::true_type>,
        // method 'aMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'aPixmap'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'aFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'isFindfriendReslute'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonArray, std::false_type>,
        // method 'isaAddfriendrequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'isaAddfriendanswer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'isNeedGetAllInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'TheMessageitem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'TheFrienditem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'TheBaseInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'TheOtherRequestAdd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendaMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonArray, std::false_type>,
        // method 'SaveAllinfoOk'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'PasureaMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'PasureasendMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonArray, std::false_type>,
        // method 'PrepareAllinfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'PasureNotgetmessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'PasureanotGetmessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonArray, std::false_type>
    >,
    nullptr
} };

void PasureMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PasureMessage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->aMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 1: _t->aPixmap((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 2: _t->aFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 3: _t->isFindfriendReslute((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 4: _t->isaAddfriendrequest((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 5: _t->isaAddfriendanswer((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 6: _t->isNeedGetAllInfo((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->TheMessageitem(); break;
        case 8: _t->TheFrienditem(); break;
        case 9: _t->TheBaseInfo(); break;
        case 10: _t->TheOtherRequestAdd(); break;
        case 11: _t->sendaMessage((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 12: _t->SaveAllinfoOk(); break;
        case 13: _t->PasureaMessage((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 14: _t->PasureasendMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[2]))); break;
        case 15: _t->PrepareAllinfo(); break;
        case 16: _t->PasureNotgetmessage((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 17: _t->PasureanotGetmessage((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PasureMessage::*)(QString , QString , QString );
            if (_t _q_method = &PasureMessage::aMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PasureMessage::*)(QString , QString , QString );
            if (_t _q_method = &PasureMessage::aPixmap; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PasureMessage::*)(QString , QString , double , QString , QString );
            if (_t _q_method = &PasureMessage::aFile; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PasureMessage::*)(QJsonArray );
            if (_t _q_method = &PasureMessage::isFindfriendReslute; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PasureMessage::*)(QString , QString , QString , QString );
            if (_t _q_method = &PasureMessage::isaAddfriendrequest; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PasureMessage::*)(QString , QString , QString , QString );
            if (_t _q_method = &PasureMessage::isaAddfriendanswer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PasureMessage::*)(bool );
            if (_t _q_method = &PasureMessage::isNeedGetAllInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PasureMessage::*)();
            if (_t _q_method = &PasureMessage::TheMessageitem; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PasureMessage::*)();
            if (_t _q_method = &PasureMessage::TheFrienditem; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (PasureMessage::*)();
            if (_t _q_method = &PasureMessage::TheBaseInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (PasureMessage::*)();
            if (_t _q_method = &PasureMessage::TheOtherRequestAdd; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (PasureMessage::*)(QJsonArray );
            if (_t _q_method = &PasureMessage::sendaMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (PasureMessage::*)();
            if (_t _q_method = &PasureMessage::SaveAllinfoOk; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
    }
}

const QMetaObject *PasureMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PasureMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPasureMessageENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PasureMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void PasureMessage::aMessage(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PasureMessage::aPixmap(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PasureMessage::aFile(QString _t1, QString _t2, double _t3, QString _t4, QString _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PasureMessage::isFindfriendReslute(QJsonArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PasureMessage::isaAddfriendrequest(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PasureMessage::isaAddfriendanswer(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PasureMessage::isNeedGetAllInfo(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PasureMessage::TheMessageitem()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void PasureMessage::TheFrienditem()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void PasureMessage::TheBaseInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void PasureMessage::TheOtherRequestAdd()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void PasureMessage::sendaMessage(QJsonArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void PasureMessage::SaveAllinfoOk()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}
QT_WARNING_POP
