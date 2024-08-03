#ifndef ALLWORKER_H
#define ALLWORKER_H

#include "dealaddfriend.h"
#include "dealfile.h"
#include "dealmessage.h"
#include "dealuserconnect.h"
#include "dealuserlogin.h"
#include "dealuserregit.h"
#include "onlineuser.h"
#include <QObject>



class AllWorker : public QObject
{
    Q_OBJECT
public:
    explicit AllWorker(QString logfilepath, QString AlluserInfoDir, QString AllFileDir, QString Alluserinfopath, QString Allfileinfopath,
                       QString AllserverDir, QObject *parent = nullptr);
    ~AllWorker();
signals:
    void start(QHostAddress serverip);

    void deleteOK();

    void OnlineUser(AllOnlineUser*onlineusers);
public slots:
    void deleteAll();


    void saveThisinfo(QString info);

    void startInitServer(QHostAddress ip);
public:
    AllOnlineUser*onlineusers;
private:
    QString alluserinfoDir;
    QString alluserbaseinfoPath;

    QString allfileinfoDir;
    QString allfielinfoPath;


    QString allserverDir;

    QMap<QString,QString>*AllidAndpassword;

    QMap<QString,QPair<QString,QString>>*baseinfo;


    QMap<int,QString>*AllwaitConnect;

    QMap<QString,QMap<QString,QJsonArray>*>*AllNotGetMessaeg;


    QThread*online_t;

    DealUserLogin*dealLogin;

    QThread*Login_t;

    DealUserRegit*dealRegit;
    QThread*Regit_t;

    DealUserConnect*Dealconnect;
    QThread*connect_t;

    DealFile*file;
    QThread* file_t;

    DealMessage*Dealmessage;
    QThread* message_t;


    DealAddFriend*Dealaddfriend;
    QThread* add_t;

    QFile* logfile;
    QString logFilepath;


    bool haveInit=false;
};

#endif // ALLWORKER_H
