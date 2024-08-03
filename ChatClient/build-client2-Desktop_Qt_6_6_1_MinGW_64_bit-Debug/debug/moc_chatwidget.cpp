/****************************************************************************
** Meta object code from reading C++ file 'chatwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client2/chatwidget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatwidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSChatWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSChatWidgetENDCLASS = QtMocHelpers::stringData(
    "ChatWidget",
    "SendaMessage",
    "",
    "friendid",
    "amessage",
    "SendaFile",
    "filepath",
    "aMessagewidget*",
    "widget",
    "GetaFile",
    "savefilepath",
    "key",
    "HaveDelete",
    "on_send_clicked",
    "on_file_clicked",
    "on_pixmap_clicked",
    "SendaFileOk"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSChatWidgetENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[11];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[9];
    char stringdata5[10];
    char stringdata6[9];
    char stringdata7[16];
    char stringdata8[7];
    char stringdata9[9];
    char stringdata10[13];
    char stringdata11[4];
    char stringdata12[11];
    char stringdata13[16];
    char stringdata14[16];
    char stringdata15[18];
    char stringdata16[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSChatWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSChatWidgetENDCLASS_t qt_meta_stringdata_CLASSChatWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "ChatWidget"
        QT_MOC_LITERAL(11, 12),  // "SendaMessage"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 8),  // "friendid"
        QT_MOC_LITERAL(34, 8),  // "amessage"
        QT_MOC_LITERAL(43, 9),  // "SendaFile"
        QT_MOC_LITERAL(53, 8),  // "filepath"
        QT_MOC_LITERAL(62, 15),  // "aMessagewidget*"
        QT_MOC_LITERAL(78, 6),  // "widget"
        QT_MOC_LITERAL(85, 8),  // "GetaFile"
        QT_MOC_LITERAL(94, 12),  // "savefilepath"
        QT_MOC_LITERAL(107, 3),  // "key"
        QT_MOC_LITERAL(111, 10),  // "HaveDelete"
        QT_MOC_LITERAL(122, 15),  // "on_send_clicked"
        QT_MOC_LITERAL(138, 15),  // "on_file_clicked"
        QT_MOC_LITERAL(154, 17),  // "on_pixmap_clicked"
        QT_MOC_LITERAL(172, 11)   // "SendaFileOk"
    },
    "ChatWidget",
    "SendaMessage",
    "",
    "friendid",
    "amessage",
    "SendaFile",
    "filepath",
    "aMessagewidget*",
    "widget",
    "GetaFile",
    "savefilepath",
    "key",
    "HaveDelete",
    "on_send_clicked",
    "on_file_clicked",
    "on_pixmap_clicked",
    "SendaFileOk"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSChatWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   62,    2, 0x06,    1 /* Public */,
       5,    2,   67,    2, 0x06,    4 /* Public */,
       9,    3,   72,    2, 0x06,    7 /* Public */,
      12,    1,   79,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    0,   82,    2, 0x08,   13 /* Private */,
      14,    0,   83,    2, 0x08,   14 /* Private */,
      15,    0,   84,    2, 0x08,   15 /* Private */,
      16,    2,   85,    2, 0x08,   16 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonArray,    3,    4,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 7,   10,   11,    8,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject ChatWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSChatWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSChatWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSChatWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ChatWidget, std::true_type>,
        // method 'SendaMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonArray, std::false_type>,
        // method 'SendaFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<aMessagewidget *, std::false_type>,
        // method 'GetaFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<aMessagewidget *, std::false_type>,
        // method 'HaveDelete'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_send_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_file_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pixmap_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SendaFileOk'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void ChatWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SendaMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[2]))); break;
        case 1: _t->SendaFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<aMessagewidget*>>(_a[2]))); break;
        case 2: _t->GetaFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<aMessagewidget*>>(_a[3]))); break;
        case 3: _t->HaveDelete((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->on_send_clicked(); break;
        case 5: _t->on_file_clicked(); break;
        case 6: _t->on_pixmap_clicked(); break;
        case 7: _t->SendaFileOk((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< aMessagewidget* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< aMessagewidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChatWidget::*)(QString , QJsonArray );
            if (_t _q_method = &ChatWidget::SendaMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ChatWidget::*)(QString , aMessagewidget * );
            if (_t _q_method = &ChatWidget::SendaFile; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ChatWidget::*)(QString , QString , aMessagewidget * );
            if (_t _q_method = &ChatWidget::GetaFile; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ChatWidget::*)(QString );
            if (_t _q_method = &ChatWidget::HaveDelete; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *ChatWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSChatWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ChatWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ChatWidget::SendaMessage(QString _t1, QJsonArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChatWidget::SendaFile(QString _t1, aMessagewidget * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChatWidget::GetaFile(QString _t1, QString _t2, aMessagewidget * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ChatWidget::HaveDelete(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
