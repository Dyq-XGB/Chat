#ifndef DEALMESSAGE_H
#define DEALMESSAGE_H

#include "onlineuser.h"
#include <QObject>
#include <QUdpSocket>
class GetMessage;
class SendMessage;

class DealMessage : public QObject
{
    Q_OBJECT
public:
    explicit DealMessage(QString alluserinfoDir,AllOnlineUser*OnlineUsers,
                         QMap<QString,QMap<QString,QJsonArray>*>*AllNotGetMessaeg,
                         QObject *parent = nullptr);
    virtual ~DealMessage();
public slots:
    void startwork(QHostAddress ip);
private slots:
    void dealamessage(QByteArray bytes,QHostAddress ip,unsigned short port);
signals:
    void startdo(QHostAddress ip);

    void saveThisinfo(QString info);

    void SendThisMessage(QByteArray bytes,QHostAddress ip,unsigned short port);
private:
    AllOnlineUser*Onlineusers;
    QMap<QString,QMap<QString,QJsonArray>*>*AllNotGetMessaeg;

    GetMessage *get;
    QThread*get_t;
    QString userInfoDir;
};

class GetMessage : public QObject
{
    Q_OBJECT
public:
    explicit GetMessage(QObject *parent = nullptr);
    virtual ~GetMessage();
public slots:
    void startwork(QHostAddress ip);

    void SendMessage(QByteArray bytes,QHostAddress ip,unsigned short port);
private slots:
    void GetaMessage();
signals:
    void amessage(QByteArray byts,QHostAddress ip,unsigned short port);

    void saveThisinfo(QString info);
private:
    unsigned short port=10016;
    QUdpSocket*get_udp;
};


#endif // DEALMESSAGE_H
