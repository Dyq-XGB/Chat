#ifndef AONLINEUSER_H
#define AONLINEUSER_H

#include "qhostaddress.h"
#include "qtcpsocket.h"
#include <QJsonArray>
#include <QObject>
#include <qjsonobject.h>
#include <qudpsocket.h>

class aOnlineUser : public QObject
{
    Q_OBJECT
public:
    explicit aOnlineUser(QString alluserinfoDir,QString id,QHostAddress ip,unsigned short port,
                         QTcpSocket*socket,QObject *parent=nullptr);
    ~ aOnlineUser();
public:
    QString getId() const;
    QPair<QHostAddress, unsigned short> getIpAndPort() const;

private slots:
    void DisConnect();

    void GetUserNeedSaveInfo();
signals:
    void UserDisConnect(QString id,QHostAddress ip,unsigned short port,QString time);
private:
    void SaveAllInfo(QByteArray &bytes);
private:
    QString Id;
    QHostAddress ip;
    unsigned short port;
    QString LoginTime;
    QTcpSocket*socket;

    QString saveDir;

    QString savepath;
};



#endif // AONLINEUSER_H
