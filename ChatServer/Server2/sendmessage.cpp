#include "sendmessage.h"

SendMessage::SendMessage(OnlineUser *online, AllUser *all, QObject *parent)
    : QObject{parent},onlineuser(online),alluser(all)
{}

void SendMessage::sendmessage(QJsonArray *amessage)
{
    QString fromid=amessage->at(1).toString();
    QString toid=amessage->at(2).toString();
}
