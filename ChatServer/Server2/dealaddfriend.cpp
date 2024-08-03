#include "dealaddfriend.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QThread>


DealAddFriend::DealAddFriend(QString userinfodir, QMap<QString,QPair<QString,QString>>*baseinfo, QObject *parent)
    : QObject{parent},userinfodir(userinfodir),baseinfo(baseinfo)
{

}

void DealAddFriend::startwork(QHostAddress ip)
{
    qDebug()<<"DealAddFriend::startwork()";
    udp=new QUdpSocket();
    udp->bind(ip,port);
    connect(udp,&QUdpSocket::readyRead,this,&DealAddFriend::Getrequest);
    connect(udp,&QUdpSocket::errorOccurred,this,[=](QUdpSocket::SocketError error){emit saveThisInfo(QString("DealAddFriend:")+QString::number(error));});

    infodir=userinfodir;
    pasure=new PurseInfo(userinfodir,baseinfo);
    connect(this,&DealAddFriend::pasureaInfo,pasure,&PurseInfo::pasureinfo);
    connect(pasure,&PurseInfo::saveThisInfo,this,&DealAddFriend::saveThisInfo);

    connect(pasure,&PurseInfo::FindReslute,this,&DealAddFriend::SendFindReslute);
    t=new QThread();
    pasure->moveToThread(t);
    t->start();

    bool b1=udp->isOpen();
    bool b2=udp->isValid();


    emit saveThisInfo(QString("DeallAddFriend StartWork")+"isOpen:"+QString::number(b1)+"isValid:"+QString::number(b2));

}

void DealAddFriend::SendFindReslute(QByteArray bytes, QHostAddress ip, unsigned short port)
{
    udp->writeDatagram(bytes,ip,port);
}


void DealAddFriend::Getrequest()
{
    qDebug()<<"DealAddFriend::Getrequest()";
    QByteArray bytes;
    bytes.resize(udp->pendingDatagramSize());
    QHostAddress ip;
    unsigned short port;
    udp->readDatagram(bytes.data(),bytes.size(),&ip,&port);
    emit saveThisInfo(QString("aFindrequest"+ip.toString()));
    emit pasureaInfo(bytes,ip,port);
}



PurseInfo::PurseInfo(QString userinfodir, QMap<QString, QPair<QString, QString> > *baseinfo, QObject *parent)
    : QObject{parent},baseinfo(baseinfo)
{
    qDebug()<<"PurseInfo::PurseInfo(QMap<QString, QString> *allIdAndNAme, QObject *parent)";
    infodir=userinfodir;
}

void PurseInfo::pasureinfo(QByteArray bytes, QHostAddress ip, unsigned short port)
{
    qDebug()<<"PurseInfo::pasureinfo(QByteArray bytes, QHostAddress ip, unsigned short port)";
    QString id(bytes);
    QString type="findfriendreslute";
    QJsonArray array;
    array.push_back(type);
    QMap<QString,QPair<QString,QString>>::Iterator i=baseinfo->find(id);
    if(i!=baseinfo->end())
    {
        qDebug()<<"i!=allIdAndNAme->end()";
        QPair<QString,QString> nameAndpix=i.value();
        qDebug()<<nameAndpix.first;
        qDebug()<<id;
        array.push_back(id);
        array.push_back(nameAndpix.first);
        array.push_back(nameAndpix.second);
    }
    QJsonDocument doc(array);

    QString reslute="找到好友";
    if(array.size()==1)
        reslute="未找到";
    emit saveThisInfo(ip.toString()+"findfriend:"+id+"reslute:"+reslute);

    emit FindReslute(doc.toJson(),ip,port);
}


