#ifndef DEALMESSAGE_H
#define DEALMESSAGE_H

#include "qudpsocket.h"
#include <QJsonArray>
#include <QObject>

class DealMessage : public QObject
{
    Q_OBJECT
public:
    explicit DealMessage(QHostAddress serverip,unsigned short port,QObject *parent = nullptr);
    ~DealMessage();
public slots:
    void startwork();
    void SendaMessage(QJsonArray amessage);

    void FindFriend(QString id);


private slots:
    void Getinfo();
signals:
    void aMessage(QByteArray bytes);
    void FindFriendReslute(QByteArray byte);

private:
    QUdpSocket*udp;
    unsigned short serverPort=10016;
    QHostAddress serverip;
    unsigned short port;

    unsigned short findfriendport=10030;
};

#endif // DEALMESSAGE_H
