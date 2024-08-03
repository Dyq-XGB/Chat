#include "onlineuser.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QThread>



AllOnlineUser::AllOnlineUser(QString alluserinfoDir,QMap<int, QString> *AllwaitConnect,
                             QMap<QString, QMap<QString, QJsonArray> *> *AllNotGetMessaeg,
                             QObject *parent)
    : QObject{parent},AllwaitConnect(AllwaitConnect),AllNotGetMessaeg(AllNotGetMessaeg)
{
    qDebug()<<"AllOnlineUser";
    UserInfoDir=alluserinfoDir;
    OnlineUsers=new QMap<QString,aOnlineUser*>();
}

AllOnlineUser::~AllOnlineUser()
{
    QMap<QString,aOnlineUser*>::Iterator i=OnlineUsers->begin();
    while(i!=OnlineUsers->end())
    {
        delete i.value();
        ++i;
    }
    delete OnlineUsers;
}

bool AllOnlineUser::isExist(QString &id)
{
    return OnlineUsers->contains(id);
}

QPair<QHostAddress, unsigned short> AllOnlineUser::GetOnlineUserIpAndPort(QString &id)
{
    return OnlineUsers->find(id).value()->getIpAndPort();
}

void AllOnlineUser::GetUserAllInfo(QJsonDocument& doc,QString id)
{
    qDebug()<<"AllOnlineUser::GetUserAllInfo(QJsonDocument& doc,QString id)"<<id;

    QString filepath=UserInfoDir+id+"/"+id+".json";
    QFile file(filepath);
    file.open(QFile::ReadOnly);
    QByteArray bytes=file.readAll();
    doc=QJsonDocument::fromJson(bytes);
}



void AllOnlineUser::CreateAonline(qintptr handle)
{


    emit saveThisinfo("AllOnlineUser::CreateAonline(qintptr handle)"+QString::number(handle)+"try to connect");
    qDebug()<<"AllOnlineUser::CreateAonline(qintptr handle)";
    QTcpSocket*socket=new QTcpSocket();
    socket->setSocketDescriptor(handle);
    if(!socket->waitForReadyRead(5000))
    {
        qDebug()<<"连接超时！";
        socket->close();
        delete socket;
        return;
    }

    QByteArray bytes=socket->readAll();
    int LoginKey=bytes.toInt();
    qDebug()<<"得到LoginKey"<<LoginKey;

    QMap<int,QString>::Iterator i=AllwaitConnect->find(LoginKey);
    if(i==AllwaitConnect->end())
    {
        qDebug()<<"LoginKey:"<<LoginKey<<"NotExist!";
        socket->close();
        delete socket;
        return;
    }
    QString id=i.value();
    qDebug()<<"确实在等待队列中  id:"<<id;
    AllwaitConnect->remove(LoginKey);

    QHostAddress ip=socket->peerAddress();
    unsigned short port=socket->peerPort();
    qDebug()<<"连接成功"<<"Id:"<<id<<ip<<port;

    QByteArray notgetmessage;
    QMap<QString,QJsonArray>* x=AllNotGetMessaeg->find(id).value();
    if(!x->isEmpty())
    {
        qDebug()<<"有未接收的信息";
        QJsonObject object;

        QMap<QString,QJsonArray>::Iterator xx=x->begin();
        while(xx!=x->end())
        {
            object.insert(xx.key(),xx.value());
            ++xx;
        }

        QJsonDocument doc(object);
        notgetmessage.append(doc.toJson());

        x->clear();
    }
    qDebug()<<"没有未接受的信息";

    int size=notgetmessage.size();
    qDebug()<<"没有接收的信息大小："<<size;
    QByteArray needsend;
    needsend.setNum(size);
    socket->write(needsend);

    if(socket->waitForReadyRead(5000))
    {
        QByteArray bytes=socket->readAll();
        qDebug()<<QString(bytes);
    }
    int havesend=0;
    qDebug()<<"开始发送没有接收的信息";
    while(havesend!=size)
        havesend+=socket->write(notgetmessage);
    qDebug()<<"未接收的信息发送完成";

    if(socket->waitForReadyRead(10000))
    {
        QByteArray bytes=socket->readAll();
        QString request(bytes);
        qDebug()<<request;
        if(request=="GetAllInfo")
        {
            qDebug()<<"用户需要所有数据";
            QJsonDocument doc;
            GetUserAllInfo(doc,id);
            QByteArray bytes(doc.toJson());
            int size=bytes.size();
            qDebug()<<"所有信息大小："<<size;
            QByteArray needsend;
            needsend.setNum(size);
            socket->write(needsend);
            int havesend=0;
            if(socket->waitForReadyRead())
            {
                qDebug()<<"开始发送所有信息";
                QByteArray bytes=socket->readAll();
                qDebug()<<QString(bytes);
            }
            while(havesend!=size)
            {
                qDebug()<<"已发送："<<(havesend+=socket->write(bytes));
            }
        }
    }
    aOnlineUser*aonline=new aOnlineUser(UserInfoDir,id,ip,port,socket);
    connect(aonline,&aOnlineUser::UserDisConnect,this,&AllOnlineUser::aUserDisConnect);
    OnlineUsers->insert(id,aonline);
    emit aconnect(id,ip,port,QTime::currentTime().toString());
    emit saveThisinfo("connect clinet ok:"+QString::number(handle));
}



void AllOnlineUser::aUserDisConnect(QString Id, QHostAddress ip, unsigned short port, QString time)
{
    qDebug()<<"aUserDisConnect"<<Id<<ip<<port<<time;
    delete OnlineUsers->find(Id).value();
    OnlineUsers->remove(Id);
    emit adisconnect(Id,time);
    emit saveThisinfo("aUserDisConnect:"+Id+ip.toString());
}





