#include "dealmessage.h"

#include <QJsonArray>
#include <QJsonDocument>

DealMessage::DealMessage(QHostAddress serverip, unsigned short port, QObject *parent)
    : QObject{parent},serverip(serverip),port(port)
{

}
DealMessage::~DealMessage()
{
    qDebug()<<"DealMessage::~DealMessage()";
    delete udp;
}
void DealMessage::startwork()
{
    qDebug()<<"DealMessage::startwork()";
    udp=new QUdpSocket();
    udp->bind(port);
    connect(udp,&QUdpSocket::readyRead,this,&DealMessage::Getinfo);
}

void DealMessage::SendaMessage(QJsonArray amessage)
{
    qDebug()<<"DealMessage::SendaMessage(QJsonArray amessage)";
    QJsonDocument doc(amessage);
    udp->writeDatagram(doc.toJson(),serverip,serverPort);
    udp->flush();
}

void DealMessage::FindFriend(QString id)
{
    qDebug()<<"DealMessage::FindFriend(QString id)";
    udp->writeDatagram(id.toUtf8(),serverip,findfriendport);
    udp->flush();
}



void DealMessage::Getinfo()
{
    qDebug()<<"DealMessage::Getinfo()";
    qDebug()<<udp->pendingDatagramSize();
    QByteArray bytes;
    bytes.resize(udp->pendingDatagramSize());
    qDebug()<<"1";
    udp->readDatagram(bytes.data(),bytes.size());
    qDebug()<<"2";

    if(udp->bytesAvailable())
        qDebug()<<"udp->bytesAvailable()";
    else
        qDebug()<<"!bytesAvaliable";
    emit aMessage(bytes);
    qDebug()<<"3";
}
