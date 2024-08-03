QT       += core gui
QT +=network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addfriendwidget.cpp \
    afindreslute.cpp \
    amessagewidget.cpp \
    chatwidget.cpp \
    connecttoserver.cpp \
    dealfile.cpp \
    dealmessage.cpp \
    frienditem.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    messageitem.cpp \
    pasuremessage.cpp \
    regitdialog.cpp \
    waitanswer.cpp

HEADERS += \
    addfriendwidget.h \
    afindreslute.h \
    amessagewidget.h \
    chatwidget.h \
    connecttoserver.h \
    dealfile.h \
    dealmessage.h \
    frienditem.h \
    logindialog.h \
    mainwindow.h \
    messageitem.h \
    pasuremessage.h \
    regitdialog.h \
    waitanswer.h

FORMS += \
    addfriendwidget.ui \
    afindreslute.ui \
    amessagewidget.ui \
    chatwidget.ui \
    frienditem.ui \
    logindialog.ui \
    mainwindow.ui \
    messageitem.ui \
    regitdialog.ui \
    waitanswer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc

RC_ICONS=favicon.ico
