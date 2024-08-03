#ifndef ONLINEUSER_H
#define ONLINEUSER_H

#include "aonlineuser.h"
#include <QTcpSocket>
#include <QObject>
#include <QHostAddress>
#include <QVector>
#include <QPair>


class AllOnlineUser : public QObject
{
    Q_OBJECT
public:
    explicit AllOnlineUser(QString alluserinfoDir, QMap<int,QString>*AllwaitConnect,
                           QMap<QString,QMap<QString,QJsonArray>*>*AllNotGetMessaeg,
                           QObject *parent = nullptr);
    ~AllOnlineUser();
signals:
    void aconnect(QString id,QHostAddress ip,unsigned short port,QString time);
    void adisconnect(QString id,QString time);

    void saveThisinfo(QString info);
public:
    bool isExist(QString& id);
    QPair<QHostAddress,unsigned short> GetOnlineUserIpAndPort(QString&id);
private:
    void GetUserAllInfo(QJsonDocument &doc, QString id);
public slots:
    void CreateAonline(qintptr handle);
private slots:
    void aUserDisConnect(QString Id,QHostAddress ip,unsigned short port,QString time);
private:
    QMap<int,QString>*AllwaitConnect;
    QMap<QString,aOnlineUser*>*OnlineUsers;
    QMap<QString,QMap<QString,QJsonArray>*>*AllNotGetMessaeg;


    QString UserInfoDir;
};



#endif // ONLINEUSER_H
