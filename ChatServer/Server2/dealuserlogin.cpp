#include "dealuserlogin.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>


DealUserLogin::DealUserLogin(QMap<QString, QString> *AllidAndpassword,
                             QMap<int, QString> *AllwaitConnect, QObject *parent)
    : QObject{parent},AllidAndpassword(AllidAndpassword),AllwaitConnect(AllwaitConnect)
{

}

DealUserLogin::~DealUserLogin()
{
    qDebug()<<"~DealUserLogin()";
    delete getinfo;

    getInfomationThread->quit();
    getInfomationThread->wait();

    delete getInfomationThread;

}

void DealUserLogin::startwork(QHostAddress ip)
{
    getinfo=new GetLoginInfomation();
    connect(this,&DealUserLogin::dowork,getinfo,&GetLoginInfomation::startwork);
    connect(getinfo,&GetLoginInfomation::LoginInfomation,this,&DealUserLogin::DealLoginInfomation);
    connect(getinfo,&GetLoginInfomation::saveThisinfo,this,&DealUserLogin::saveThisinfo);
    connect(this,&DealUserLogin::SendLoginResluteToUser,getinfo,&GetLoginInfomation::SendResluteToUser);

    getInfomationThread=new QThread();
    getinfo->moveToThread(getInfomationThread);
    getInfomationThread->start();
    emit dowork(ip);


    emit saveThisinfo(QString("DealUserLogin::startwork()"));
    qDebug()<<"DealUserLogin::startwork()"<<QThread::currentThreadId();
}

void DealUserLogin::DealLoginInfomation(QByteArray bytes, QHostAddress ip, unsigned short port)
{
    qDebug()<<"DealLoginInfomation(QByteArray bytes, QHostAddress ip, unsigned short port)"<<ip<<port;
    QByteArray answer;
    QJsonDocument doc=QJsonDocument::fromJson(bytes);
    QJsonArray idAndpasswor(doc.array());
    QString id=idAndpasswor.at(0).toString();
    QString password=idAndpasswor.at(1).toString();
    qDebug()<<"id:"<<id<<"password:"<<password;
    int ans=-1;
    if(isRight(id,password))
    {
        qDebug()<<"isright";
        ans=AllwaitConnect->size();
        answer.setNum(ans);
        AllwaitConnect->insert(ans,id);
    }
    else
    {
        qDebug()<<"isfalse";
        answer.setNum(ans);
    }

    if(ans==-1)
        emit saveThisinfo(ip.toString()+"loginfalse"+id+"   "+password);
    else
        emit saveThisinfo(ip.toString()+"loginsuccess"+id);

    emit SendLoginResluteToUser(answer,ip,port);
}


bool DealUserLogin::isRight(QString &id, QString &password)
{
    QMap<QString,QString>::Iterator i=AllidAndpassword->find(id);

    if(i==AllidAndpassword->end())
        return false;
    else
    {
        QString rightpassword=i.value();
        qDebug()<<"rightpassword"<<rightpassword;
        if(rightpassword==password)
            return true;
        else
            return false;
    }
}

GetLoginInfomation::GetLoginInfomation(QObject *parent)
    :QObject(parent)
{

}

GetLoginInfomation::~GetLoginInfomation()
{
    udp->close();
    delete udp;
}

void GetLoginInfomation::startwork(QHostAddress ip)
{
    udp=new QUdpSocket();
    udp->bind(ip,Port);
    connect(udp,&QUdpSocket::readyRead,this,&GetLoginInfomation::GetInfo);
    connect(udp,&QUdpSocket::errorOccurred,this,[=](QUdpSocket::SocketError error){emit saveThisinfo(QString("GetLoginInfomation:")+QString::number(error));});
    bool b1=udp->isOpen();
    bool b2=udp->isValid();

    emit saveThisinfo(QString("GetLoginInfomation::startwork()")+"isOpen:"+QString::number(b1)+"isValid:"+QString::number(b2));
    qDebug()<<"GetLoginInfomation::startwork()"<<QThread::currentThreadId();
}

void GetLoginInfomation::SendResluteToUser(QByteArray bytes, QHostAddress ip, unsigned short port)
{
    udp->writeDatagram(bytes,ip,port);
}

void GetLoginInfomation::GetInfo()
{
    qDebug()<<"GetLoginInfomation::GetInfo()";
    QByteArray bytes;
    bytes.resize(udp->pendingDatagramSize());
    QHostAddress ip;
    unsigned short port;
    udp->readDatagram(bytes.data(),bytes.size(),&ip,&port);
    emit LoginInfomation(bytes,ip,port);

    emit saveThisinfo("GetLoginInfomation::GetInfo()");
}








