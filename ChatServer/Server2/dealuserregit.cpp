#include "dealuserregit.h"

#include <QDir>
#include <QJsonArray>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRandomGenerator>

DealUserRegit::DealUserRegit(QString alluserinfoDir,QMap<QString, QString> *AllidAndpassword, QMap<QString,QPair<QString,QString>>*baseinfo,
                             QMap<QString, QMap<QString, QJsonArray> *> *AllNotGetMessaeg, QObject *parent)
    : QObject{parent},AllidAndpassword(AllidAndpassword),baseinfo(baseinfo),AllNotGetMessaeg(AllNotGetMessaeg)
{
    AllUserInfoFileDir=alluserinfoDir;
    userBaseInfoPath=AllUserInfoFileDir+"AlluserBaseinfo.json";
}

DealUserRegit::~DealUserRegit()
{
    qDebug()<<"DealUserRegit::~DealUserRegit()";
}

void DealUserRegit::startwork(QHostAddress ip)
{
    getinfo=new GetRegitInfomtion();
    connect(this,&DealUserRegit::startdo,getinfo,&GetRegitInfomtion::startwork);
    connect(getinfo,&GetRegitInfomtion::RegitInfomation,this,&DealUserRegit::DealregitInfomation);
    connect(getinfo,&GetRegitInfomtion::saveThisinfo,this,&DealUserRegit::saveThisinfo);
    connect(this,&DealUserRegit::SendIdToUser,getinfo,&GetRegitInfomtion::SendReslute);
    GetInfoThread=new QThread();
    getinfo->moveToThread(GetInfoThread);
    GetInfoThread->start();
    emit startdo(ip);
    emit saveThisinfo(QString("DealUserRegit::startwork()")+"isOpen:");
    qDebug()<<"DealUserRegit::startwork()"<<QThread::currentThreadId();
}

void DealUserRegit::DealregitInfomation(QByteArray bytes, QHostAddress ip, unsigned short port)
{
    qDebug()<<"DealregitInfomation(QByteArray bytes, QHostAddress ip, unsigned short port)"
             <<ip<<port;
    QJsonDocument infodoc=QJsonDocument::fromJson(bytes);
    QJsonArray infoarray(infodoc.array());
    QString nickname=infoarray.at(0).toString();
    QString password=infoarray.at(1).toString();
    QString pixstr=infoarray.at(2).toString();


    qDebug()<<password;
    qDebug()<<nickname;

    QString id=CreateaUser(nickname,password,pixstr);

    emit SendIdToUser(id,ip,port);

    emit saveThisinfo(QString("DealUserRegit::DealregitInfomation  createAuser")+id+nickname+"IP:"+ip.toString()+"port:"+QString::number(port));
}

QString DealUserRegit::CreateaUser(QString nickname,QString password,QString pixstr)
{
    qDebug()<<"DealUserRegit::CreateaUser(QString password)"<<password;
    QString Id;
    do
    {
        Id=QString::number(QRandomGenerator::global()->bounded(100000,999999));
    }while(AllidAndpassword->contains(Id));

    QDir dir(AllUserInfoFileDir);
    dir.mkdir(Id);
    QString infomationdir=AllUserInfoFileDir+Id+"/";
    QString createtime=QDate::currentDate().toString()+"+"+QTime::currentTime().toString();

    QJsonObject base;
    base.insert("id",Id);
    base.insert("password",password);
    base.insert("nickname",nickname);
    base.insert("headshot",pixstr);
    base.insert("createtime",createtime);

    QJsonObject friends;
    QJsonArray messageitem;
    QJsonObject messagerecord;
    QJsonObject meRequestother;
    QJsonArray otherRequestme;

    QJsonObject fatherobject;
    fatherobject.insert("baseinfo",base);
    fatherobject.insert("friends",friends);
    fatherobject.insert("messageitem",messageitem);
    fatherobject.insert("messagerecord",messagerecord);
    fatherobject.insert("otherRequestme",otherRequestme);
    fatherobject.insert("meRequestother",meRequestother);


    QString infopath=infomationdir+Id+".json";

    QJsonDocument doc(fatherobject);
    QByteArray bytes=doc.toJson();
    QFile infofile(infopath);
    infofile.open(QFile::WriteOnly);
    infofile.write(bytes);
    infofile.close();

    QJsonObject notgetobject;
    QJsonDocument doc1(notgetobject);
    QByteArray bytes2=doc1.toJson();
    QString notpath=infomationdir+"notgetmessage.json";
    QFile notgetfile(notpath);
    notgetfile.open(QFile::WriteOnly);
    notgetfile.write(bytes2);
    notgetfile.close();


    AllidAndpassword->insert(Id,password);
    baseinfo->insert(Id,QPair<QString,QString>(nickname,pixstr));
    QMap<QString,QJsonArray>*ausernotget=new QMap<QString,QJsonArray>();
    AllNotGetMessaeg->insert(Id,ausernotget);

    qDebug()<<"CreateaUser:"<<Id;
    return Id;
}

bool DealUserRegit::isExist(QString &id)
{
    return AllidAndpassword->contains(id);
}


GetRegitInfomtion::GetRegitInfomtion(QObject *parent)
    :QObject(parent)
{

}

GetRegitInfomtion::~GetRegitInfomtion()
{
    udp->close();
    delete udp;
}

void GetRegitInfomtion::startwork(QHostAddress ip)
{
    udp=new QUdpSocket();
    udp->bind(ip,Port);
    connect(udp,&QUdpSocket::readyRead,this,&GetRegitInfomtion::GetInfomation);
    connect(udp,&QUdpSocket::errorOccurred,this,[=](QUdpSocket::SocketError error){emit saveThisinfo(QString("GetRegitInfomtion:")+QString::number(error));});

    bool b1=udp->isOpen();
    bool b2=udp->isValid();
    qDebug()<<"GetRegitInfomtion::startwork()"<<QThread::currentThreadId();
    emit saveThisinfo(QString("GetRegitInfomtion::startwork()")+"isOpen:"+QString::number(b1)+"isValid:"+QString::number(b2));
}

void GetRegitInfomtion::GetInfomation()
{
    qDebug()<<"GetRegitInfomtion::GetInfomation()";
    QByteArray bytes;
    bytes.resize(udp->pendingDatagramSize());
    QHostAddress ip;
    unsigned short port;
    udp->readDatagram(bytes.data(),bytes.size(),&ip,&port);
    emit RegitInfomation(bytes,ip,port);
    emit saveThisinfo(ip.toString()+"GetRegitInfomtion::GetInfomation()"+ip.toString());
}

void GetRegitInfomtion::SendReslute(QString id, QHostAddress ip, unsigned short port)
{
    udp->writeDatagram(id.toUtf8(),ip,port);
}
