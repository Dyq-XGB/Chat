#ifndef SENDMESSAGE_H
#define SENDMESSAGE_H

#include "onlineuser.h"
#include "alluser.h"
#include <QObject>

class SendMessage : public QObject
{
    Q_OBJECT
public:
    explicit SendMessage(OnlineUser*online,AllUser*all,QObject *parent = nullptr);
public slots:
    void sendmessage(QJsonArray*amessage);
private:
    OnlineUser*onlineuser;
    AllUser*alluser;
};

#endif // SENDMESSAGE_H
