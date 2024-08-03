#ifndef DEALADDFRIEND_H
#define DEALADDFRIEND_H

#include "qudpsocket.h"
#include <QObject>
class PurseInfo: public QObject
{
    Q_OBJECT
public:
    explicit PurseInfo(QString userinfodir,QMap<QString,QPair<QString,QString>>*baseinfo,QObject *parent = nullptr);

public slots:
    void pasureinfo(QByteArray bytes,QHostAddress ip,unsigned short port);
signals:
     void saveThisInfo(QString info);

    void FindReslute(QByteArray bytes,QHostAddress ip,unsigned short port);
private:
    QMap<QString,QPair<QString,QString>>*baseinfo;
    QString infodir;
};
class DealAddFriend : public QObject
{
    Q_OBJECT
public:
    explicit DealAddFriend(QString userinfodir,QMap<QString,QPair<QString,QString>>*baseinfo,QObject *parent = nullptr);
public slots:
    void startwork(QHostAddress ip);

    void SendFindReslute(QByteArray bytes,QHostAddress ip,unsigned short port);
private slots:
    void Getrequest();

signals:
    void pasureaInfo(QByteArray bytes,QHostAddress ip,unsigned short port);

    void saveThisInfo(QString info);
private:
    PurseInfo*pasure;
    QUdpSocket*udp;
    QString infodir;
    unsigned short port=10030;
    QThread*t;
    QString userinfodir;
    QMap<QString,QPair<QString,QString>>*baseinfo;
};



#endif // DEALADDFRIEND_H
