/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "signal_start_connectToServer",
    "",
    "Loginkey",
    "port",
    "needGetAllinfo",
    "startwork",
    "sendAmessage",
    "amessage",
    "HaveaFindWidget",
    "AddFriendWidget*",
    "addwidget",
    "answerThisFriend",
    "firendid",
    "array",
    "startPasure",
    "id",
    "QJsonObject&",
    "baseinfoobject",
    "friendsobject",
    "QJsonArray&",
    "messageitemarray",
    "otherRequestme",
    "QMap<QString,QJsonArray*>*",
    "messagerecord",
    "StopGetMessage",
    "SendInfoToServer",
    "on_MessageList_itemDoubleClicked",
    "QListWidgetItem*",
    "item",
    "on_FriendList_itemDoubleClicked",
    "removeaChatWidget",
    "friendid",
    "on_addFriend_clicked",
    "do_addThisFriend",
    "friendname",
    "pixpath",
    "DeleteAll",
    "aMessage",
    "message",
    "time",
    "aFile",
    "key",
    "filesize",
    "filename",
    "aPixmap",
    "pixsavepath",
    "aAddfriendanswer",
    "aAddfriendrequest",
    "setBaseinfo",
    "setFriendItem",
    "setMessageItem",
    "setOtherRequestAdd",
    "CreateaChatWidget",
    "QJsonArray*"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[110];
    char stringdata0[11];
    char stringdata1[29];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[5];
    char stringdata5[15];
    char stringdata6[10];
    char stringdata7[13];
    char stringdata8[9];
    char stringdata9[16];
    char stringdata10[17];
    char stringdata11[10];
    char stringdata12[17];
    char stringdata13[9];
    char stringdata14[6];
    char stringdata15[12];
    char stringdata16[3];
    char stringdata17[13];
    char stringdata18[15];
    char stringdata19[14];
    char stringdata20[12];
    char stringdata21[17];
    char stringdata22[15];
    char stringdata23[27];
    char stringdata24[14];
    char stringdata25[15];
    char stringdata26[17];
    char stringdata27[33];
    char stringdata28[17];
    char stringdata29[5];
    char stringdata30[32];
    char stringdata31[18];
    char stringdata32[9];
    char stringdata33[21];
    char stringdata34[17];
    char stringdata35[11];
    char stringdata36[8];
    char stringdata37[10];
    char stringdata38[9];
    char stringdata39[8];
    char stringdata40[5];
    char stringdata41[6];
    char stringdata42[4];
    char stringdata43[9];
    char stringdata44[9];
    char stringdata45[8];
    char stringdata46[12];
    char stringdata47[17];
    char stringdata48[18];
    char stringdata49[12];
    char stringdata50[14];
    char stringdata51[15];
    char stringdata52[19];
    char stringdata53[18];
    char stringdata54[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 28),  // "signal_start_connectToServer"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 8),  // "Loginkey"
        QT_MOC_LITERAL(50, 4),  // "port"
        QT_MOC_LITERAL(55, 14),  // "needGetAllinfo"
        QT_MOC_LITERAL(70, 9),  // "startwork"
        QT_MOC_LITERAL(80, 12),  // "sendAmessage"
        QT_MOC_LITERAL(93, 8),  // "amessage"
        QT_MOC_LITERAL(102, 15),  // "HaveaFindWidget"
        QT_MOC_LITERAL(118, 16),  // "AddFriendWidget*"
        QT_MOC_LITERAL(135, 9),  // "addwidget"
        QT_MOC_LITERAL(145, 16),  // "answerThisFriend"
        QT_MOC_LITERAL(162, 8),  // "firendid"
        QT_MOC_LITERAL(171, 5),  // "array"
        QT_MOC_LITERAL(177, 11),  // "startPasure"
        QT_MOC_LITERAL(189, 2),  // "id"
        QT_MOC_LITERAL(192, 12),  // "QJsonObject&"
        QT_MOC_LITERAL(205, 14),  // "baseinfoobject"
        QT_MOC_LITERAL(220, 13),  // "friendsobject"
        QT_MOC_LITERAL(234, 11),  // "QJsonArray&"
        QT_MOC_LITERAL(246, 16),  // "messageitemarray"
        QT_MOC_LITERAL(263, 14),  // "otherRequestme"
        QT_MOC_LITERAL(278, 26),  // "QMap<QString,QJsonArray*>*"
        QT_MOC_LITERAL(305, 13),  // "messagerecord"
        QT_MOC_LITERAL(319, 14),  // "StopGetMessage"
        QT_MOC_LITERAL(334, 16),  // "SendInfoToServer"
        QT_MOC_LITERAL(351, 32),  // "on_MessageList_itemDoubleClicked"
        QT_MOC_LITERAL(384, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(401, 4),  // "item"
        QT_MOC_LITERAL(406, 31),  // "on_FriendList_itemDoubleClicked"
        QT_MOC_LITERAL(438, 17),  // "removeaChatWidget"
        QT_MOC_LITERAL(456, 8),  // "friendid"
        QT_MOC_LITERAL(465, 20),  // "on_addFriend_clicked"
        QT_MOC_LITERAL(486, 16),  // "do_addThisFriend"
        QT_MOC_LITERAL(503, 10),  // "friendname"
        QT_MOC_LITERAL(514, 7),  // "pixpath"
        QT_MOC_LITERAL(522, 9),  // "DeleteAll"
        QT_MOC_LITERAL(532, 8),  // "aMessage"
        QT_MOC_LITERAL(541, 7),  // "message"
        QT_MOC_LITERAL(549, 4),  // "time"
        QT_MOC_LITERAL(554, 5),  // "aFile"
        QT_MOC_LITERAL(560, 3),  // "key"
        QT_MOC_LITERAL(564, 8),  // "filesize"
        QT_MOC_LITERAL(573, 8),  // "filename"
        QT_MOC_LITERAL(582, 7),  // "aPixmap"
        QT_MOC_LITERAL(590, 11),  // "pixsavepath"
        QT_MOC_LITERAL(602, 16),  // "aAddfriendanswer"
        QT_MOC_LITERAL(619, 17),  // "aAddfriendrequest"
        QT_MOC_LITERAL(637, 11),  // "setBaseinfo"
        QT_MOC_LITERAL(649, 13),  // "setFriendItem"
        QT_MOC_LITERAL(663, 14),  // "setMessageItem"
        QT_MOC_LITERAL(678, 18),  // "setOtherRequestAdd"
        QT_MOC_LITERAL(697, 17),  // "CreateaChatWidget"
        QT_MOC_LITERAL(715, 11)   // "QJsonArray*"
    },
    "MainWindow",
    "signal_start_connectToServer",
    "",
    "Loginkey",
    "port",
    "needGetAllinfo",
    "startwork",
    "sendAmessage",
    "amessage",
    "HaveaFindWidget",
    "AddFriendWidget*",
    "addwidget",
    "answerThisFriend",
    "firendid",
    "array",
    "startPasure",
    "id",
    "QJsonObject&",
    "baseinfoobject",
    "friendsobject",
    "QJsonArray&",
    "messageitemarray",
    "otherRequestme",
    "QMap<QString,QJsonArray*>*",
    "messagerecord",
    "StopGetMessage",
    "SendInfoToServer",
    "on_MessageList_itemDoubleClicked",
    "QListWidgetItem*",
    "item",
    "on_FriendList_itemDoubleClicked",
    "removeaChatWidget",
    "friendid",
    "on_addFriend_clicked",
    "do_addThisFriend",
    "friendname",
    "pixpath",
    "DeleteAll",
    "aMessage",
    "message",
    "time",
    "aFile",
    "key",
    "filesize",
    "filename",
    "aPixmap",
    "pixsavepath",
    "aAddfriendanswer",
    "aAddfriendrequest",
    "setBaseinfo",
    "setFriendItem",
    "setMessageItem",
    "setOtherRequestAdd",
    "CreateaChatWidget",
    "QJsonArray*"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,  158,    2, 0x06,    1 /* Public */,
       6,    0,  165,    2, 0x06,    5 /* Public */,
       7,    1,  166,    2, 0x06,    6 /* Public */,
       9,    1,  169,    2, 0x06,    8 /* Public */,
      12,    2,  172,    2, 0x06,   10 /* Public */,
      15,    6,  177,    2, 0x06,   13 /* Public */,
      25,    0,  190,    2, 0x06,   20 /* Public */,
      26,    0,  191,    2, 0x06,   21 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      27,    1,  192,    2, 0x08,   22 /* Private */,
      30,    1,  195,    2, 0x08,   24 /* Private */,
      31,    1,  198,    2, 0x08,   26 /* Private */,
      33,    0,  201,    2, 0x08,   28 /* Private */,
      34,    3,  202,    2, 0x08,   29 /* Private */,
      37,    0,  209,    2, 0x0a,   33 /* Public */,
      38,    3,  210,    2, 0x0a,   34 /* Public */,
      41,    5,  217,    2, 0x0a,   38 /* Public */,
      45,    3,  228,    2, 0x0a,   44 /* Public */,
      47,    3,  235,    2, 0x0a,   48 /* Public */,
      48,    4,  242,    2, 0x0a,   52 /* Public */,
      49,    0,  251,    2, 0x0a,   57 /* Public */,
      50,    0,  252,    2, 0x0a,   58 /* Public */,
      51,    0,  253,    2, 0x0a,   59 /* Public */,
      52,    0,  254,    2, 0x0a,   60 /* Public */,
      53,    3,  255,    2, 0x0a,   61 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::UShort, QMetaType::Bool,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonArray,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonArray,   13,   14,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 17, 0x80000000 | 17, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 23,   16,   18,   19,   21,   22,   24,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   32,   35,   36,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   32,   39,   40,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::QString, QMetaType::QString,   32,   42,   43,   44,   40,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   32,   46,   40,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   32,   35,   36,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   32,   35,   36,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 54,   32,   35,   24,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'signal_start_connectToServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned short, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'startwork'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendAmessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonArray, std::false_type>,
        // method 'HaveaFindWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<AddFriendWidget *, std::false_type>,
        // method 'answerThisFriend'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonArray, std::false_type>,
        // method 'startPasure'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonArray &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonArray &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMap<QString,QJsonArray*> *, std::false_type>,
        // method 'StopGetMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SendInfoToServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_MessageList_itemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_FriendList_itemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'removeaChatWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_addFriend_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'do_addThisFriend'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'DeleteAll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'aMessage'
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
        // method 'aPixmap'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'aAddfriendanswer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'aAddfriendrequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setBaseinfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setFriendItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setMessageItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setOtherRequestAdd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CreateaChatWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonArray *, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signal_start_connectToServer((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ushort>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 1: _t->startwork(); break;
        case 2: _t->sendAmessage((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 3: _t->HaveaFindWidget((*reinterpret_cast< std::add_pointer_t<AddFriendWidget*>>(_a[1]))); break;
        case 4: _t->answerThisFriend((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[2]))); break;
        case 5: _t->startPasure((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonObject&>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QJsonObject&>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QJsonArray&>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QJsonArray&>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QMap<QString,QJsonArray*>*>>(_a[6]))); break;
        case 6: _t->StopGetMessage(); break;
        case 7: _t->SendInfoToServer(); break;
        case 8: _t->on_MessageList_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 9: _t->on_FriendList_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 10: _t->removeaChatWidget((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->on_addFriend_clicked(); break;
        case 12: _t->do_addThisFriend((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 13: _t->DeleteAll(); break;
        case 14: _t->aMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 15: _t->aFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 16: _t->aPixmap((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 17: _t->aAddfriendanswer((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 18: _t->aAddfriendrequest((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 19: _t->setBaseinfo(); break;
        case 20: _t->setFriendItem(); break;
        case 21: _t->setMessageItem(); break;
        case 22: _t->setOtherRequestAdd(); break;
        case 23: _t->CreateaChatWidget((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QJsonArray*>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< AddFriendWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int , unsigned short , bool );
            if (_t _q_method = &MainWindow::signal_start_connectToServer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::startwork; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QJsonArray );
            if (_t _q_method = &MainWindow::sendAmessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(AddFriendWidget * );
            if (_t _q_method = &MainWindow::HaveaFindWidget; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , QJsonArray );
            if (_t _q_method = &MainWindow::answerThisFriend; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , QJsonObject & , QJsonObject & , QJsonArray & , QJsonArray & , QMap<QString,QJsonArray*> * );
            if (_t _q_method = &MainWindow::startPasure; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::StopGetMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::SendInfoToServer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signal_start_connectToServer(int _t1, unsigned short _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::startwork()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::sendAmessage(QJsonArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::HaveaFindWidget(AddFriendWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::answerThisFriend(QString _t1, QJsonArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::startPasure(QString _t1, QJsonObject & _t2, QJsonObject & _t3, QJsonArray & _t4, QJsonArray & _t5, QMap<QString,QJsonArray*> * _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::StopGetMessage()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MainWindow::SendInfoToServer()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
