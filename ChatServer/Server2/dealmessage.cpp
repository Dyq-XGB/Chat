#include "dealmessage.h"
#include "qjsondocument.h"
#include <QDir>
#include <QFile>
#include <QThread>
#include <QTime>


DealMessage::DealMessage(QString alluserinfoDir, AllOnlineUser* OnlineUsers,
                         QMap<QString, QMap<QString, QJsonArray> *> *AllNotGetMessaeg, QObject *parent)
    :QObject(parent),Onlineusers(OnlineUsers),AllNotGetMessaeg(AllNotGetMessaeg)
{
    userInfoDir=alluserinfoDir;
}

DealMessage::~DealMessage()
{
    delete get;
    get_t->quit();
    get_t->wait();
    delete get_t;
}

void DealMessage::startwork(QHostAddress ip)
{

    get=new GetMessage();
    connect(this,&DealMessage::startdo,get,&GetMessage::startwork);
    connect(get,&GetMessage::amessage,this,&DealMessage::dealamessage);
    connect(get,&GetMessage::saveThisinfo,this,&DealMessage::saveThisinfo);
    connect(this,&DealMessage::SendThisMessage,get,&GetMessage::SendMessage);

    get_t=new QThread();
    get->moveToThread(get_t);
    get_t->start();
    emit startdo(ip);
    emit saveThisinfo(QString("DealMessage::startwork()"));

    qDebug()<<"DealMessage::startwork()"<<QThread::currentThreadId();
}

void DealMessage::dealamessage(QByteArray bytes,QHostAddress ip, unsigned short port)
{
    qDebug()<<"DealMessage::dealamessage(QByteArray bytes, QHostAddress ip, unsigned short port)"<<ip<<port;

    QJsonDocument doc=QJsonDocument::fromJson(bytes);
    QJsonArray message(doc.array());

    QString fromid=message.at(1).toString();
    QString toid=message.at(2).toString();

    qDebug()<<message.at(0).toString()<<message.at(1).toString()<<message.at(2).toString()
             <<message.at(3).toString()<<message.at(4).toString();
    bool isExist=Onlineusers->isExist(toid);
    if(!isExist)
    {
        qDebug()<<"!isExist不在线";
        QMap<QString,QJsonArray>*allnotget=AllNotGetMessaeg->find(toid).value();
        QMap<QString,QJsonArray>::Iterator i=allnotget->find(fromid);
        if(i!=allnotget->end())
        {
            qDebug()<<"(i!=allnotget->end())";
            i.value().push_back(message);
        }
        else
        {
            qDebug()<<"i==allnotget->end()";
            QJsonArray array;
            array.push_back(message);
            allnotget->insert(fromid,array);
        }
        emit saveThisinfo(QString("DealMessage::dealamessage  ")+fromid+"  "+toid+"  firiendNotexist");
    }
    else
    {
        qDebug()<<"exist";
        QPair<QHostAddress,unsigned short>ipAndport=Onlineusers->GetOnlineUserIpAndPort(toid);

        QHostAddress ip=ipAndport.first;
        unsigned short port=ipAndport.second;
        emit saveThisinfo(QString("DealMessage::dealamessage  ")+fromid+"  "+toid +ip.toString()+QString::number(port));
        emit SendThisMessage(bytes,ip,port);
    }
}

//=========================GetMessage=============================
GetMessage::GetMessage(QObject *parent)
    : QObject(parent)
{

}

GetMessage::~GetMessage()
{
    qDebug()<<"GetMessage::~GetMessage()";
    get_udp->close();
    delete get_udp;
}

void GetMessage::startwork(QHostAddress ip)
{
    get_udp=new QUdpSocket();
    get_udp->bind(ip,port);

    connect(get_udp,&QUdpSocket::readyRead,this,&GetMessage::GetaMessage);
    connect(get_udp,&QUdpSocket::errorOccurred,this,[=](QUdpSocket::SocketError error){emit saveThisinfo(QString("GetMessage:")+QString::number(error));});
    bool b1=get_udp->isOpen();
    bool b2=get_udp->isValid();

    emit saveThisinfo(QString("GetMessage::startwork()")+"isOpen:"+QString::number(b1)+"isValid:"+QString::number(b2));
    qDebug()<<" GetMessage::startwork()"<<QThread::currentThreadId();
}

void GetMessage::SendMessage(QByteArray bytes, QHostAddress ip, unsigned short port)
{
    get_udp->writeDatagram(bytes,ip,port);
    get_udp->flush();
    emit saveThisinfo("SendMessageTo:"+ip.toString()+QString::number(port));
}

void GetMessage::GetaMessage()
{
    QHostAddress ip;
    unsigned short port;
    QByteArray bytes;
    bytes.resize(get_udp->pendingDatagramSize());
    get_udp->readDatagram(bytes.data(),bytes.size(),&ip,&port);
    emit amessage(bytes,ip,port);
    emit saveThisinfo("GetMessage::GetaMessage()");
}


