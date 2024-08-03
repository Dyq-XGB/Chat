#include "pasuremessage.h"

#include <QDataStream>
#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonDocument>
#include <QJsonObject>

PasureMessage::PasureMessage(QString SavePxiDir, QString clientInfoDir, QString friendpixmap,
                             QString id, QJsonObject &Baseinfoobject, QJsonObject &Friendsobject,
                             QJsonArray &Messageitemarray, QJsonArray &OtherRequestme,
                             QMap<QString, QJsonArray *> *Messagerecord, QObject *parent)
    : QObject{parent},SavePixDir(SavePxiDir),clientInfoDir(clientInfoDir),friendpixmap(friendpixmap)
    ,baseinfoobject(Baseinfoobject),friendsobject(Friendsobject),messageitemarray(Messageitemarray),
    otherRequestme(OtherRequestme),
    messagerecord(Messagerecord),Id(id)
{

}

PasureMessage::~PasureMessage()
{
    qDebug()<<"PasureMessage::~PasureMessage()";
}

void PasureMessage::PrepareAllinfo()//准备用户数据
{
    qDebug()<<" PasureMessage::PrepareAllinfo(QString id)//准备用户数据";


    bool needGetAllinfo = false;
    QDir allinfodir(clientInfoDir);
    bool isexist=allinfodir.exists(Id);
    if(isexist)
    {
        qDebug()<<"isexist";
        QString infodir=clientInfoDir+Id+"/"+Id+".json";

        QFile infofile(infodir);
        infofile.open(QFile::ReadOnly);
        QByteArray bytes=infofile.readAll();
        infofile.close();
        QJsonDocument infodoc=QJsonDocument::fromJson(bytes);
        QJsonObject infoobject(infodoc.object());

        qDebug()<<1;
        baseinfoobject=infoobject.find("baseinfo").value().toObject();
        QString pixpath=friendpixmap+Id+".png";
        QFile file(pixpath);
        bool isexist=file.exists();
        if(!isexist)
        {
            qDebug()<<"pixisnotexist";
            QString pixstr=baseinfoobject.find("headshot").value().toString();

            QByteArray bytes=QByteArray::fromBase64(pixstr.toUtf8());
            qDebug()<<bytes;
            file.open(QFile::WriteOnly);
            file.write(bytes);
            file.close();
        }
        emit TheBaseInfo();//baseinfoobject);

        qDebug()<<2;

        QJsonObject messagerecordobject=infoobject.find("messagerecord").value().toObject();
        QJsonObject::Iterator i=messagerecordobject.begin();
        while(i!=messagerecordobject.end())
        {
            QJsonArray messagearray=i.value().toArray();
            QJsonArray::Iterator x=messagearray.begin();
            while(x!=messagearray.end())
            {
                QJsonArray amessagearray=x->toArray();
                QString type=amessagearray.at(0).toString();
                if(type=="apix")
                {
                    QByteArray bytes=QByteArray::fromBase64(amessagearray.at(3).toString().toUtf8());
                    QString suffix=amessagearray.at(4).toString();
                    QString time=amessagearray.at(5).toString().remove(':');
                    QString savepath=SavePixDir+time+suffix;
                    QFile savefile(savepath);
                    savefile.open(QFile::WriteOnly);
                    savefile.write(bytes);
                    savefile.close();
                }
                ++x;
            }
            messagerecord->insert(i.key(),new QJsonArray(i.value().toArray()));
            ++i;
        }
        //emit TheMessagerecord();//messagerecord);

        qDebug()<<3;


        friendsobject=infoobject.find("friends").value().toObject();
        QJsonObject::Iterator x=friendsobject.begin();
        while(x!=friendsobject.end())
        {
            QString pixpath=friendpixmap+x.key()+".png";
            QFile pix(pixpath);
            bool isexist=pix.exists();
            if(!isexist)
            {
                QJsonArray infoarray=x.value().toArray();
                QByteArray bytes=QByteArray::fromBase64(infoarray.at(1).toString().toUtf8());
                file.open(QFile::WriteOnly);
                file.write(bytes);
                file.close();
            }
            ++x;
        }
        emit TheFrienditem();//friendsobject);

        qDebug()<<4;
        messageitemarray=infoobject.find("messageitem").value().toArray();
        emit TheMessageitem();//messageitemarray);

        otherRequestme=infoobject.find("requestaddfriend").value().toArray();//别人请求我
        QJsonArray::Iterator j=otherRequestme.begin();
        while(j!=otherRequestme.end())
        {
            QJsonArray infoarray=j->toArray();
            QString friendid=infoarray.at(1).toString();
            QString pixpath=friendpixmap+friendid+".png";
            QFile pix(pixpath);
            bool isexist=pix.exists();
            if(!isexist)
            {
                QByteArray bytes=QByteArray::fromBase64(infoarray.at(4).toString().toUtf8());
                file.open(QFile::WriteOnly);
                file.write(bytes);
                file.close();
            }
            ++j;
        }
        emit TheOtherRequestAdd();//otherRequestme);
        qDebug()<<5;
        havePasureAllinfo=true;
    }
    else
    {
        needGetAllinfo=true;
        qDebug()<<"!exist";
    }
    if(!haveSendifneed)
    {
        haveSendifneed=true;
        emit isNeedGetAllInfo(needGetAllinfo);
    }
}

void PasureMessage::PasureNotgetmessage(QByteArray bytes)//解析所有没有得到的信息
{
    qDebug()<<"bytes size:"<<bytes.size();
    qDebug()<<"PasureMessage::PasureNotgetmessage(QByteArray bytes)//解析所有没有得到的信息";
    qDebug()<<havePasureAllinfo;
    if(havePasureAllinfo==false)
        PrepareAllinfo();

    qDebug()<<"ParepareAllinfoOK";
    QJsonDocument doc=QJsonDocument::fromJson(bytes);
    QJsonObject allnotget(doc.object());
    qDebug()<<"allnotget size:"<<allnotget.size();

    QJsonObject::Iterator i=allnotget.begin();
    while(i!=allnotget.end())
    {
        qDebug()<<"PasuraNotgetMessage";
        QJsonArray afriendarray=i.value().toArray();

        QJsonArray::Iterator x=afriendarray.begin();
        while(x!=afriendarray.end())
        {
            PasureanotGetmessage(x->toArray());
            ++x;
        }
        ++i;
    }
}

void PasureMessage::PasureanotGetmessage(QJsonArray array)//解析一条没有得到的消息
{
    qDebug()<<"PasureMessage::PasureanotGetmessage(QJsonArray array)//解析一条没有得到的消息";
    QString type=array.at(0).toString();
    qDebug()<<type;
    if(type=="findfriendreslute")
    {
        qDebug()<<"findfriendreslute";
        if(array.size()!=1)
        {
        QByteArray pixbytes=QByteArray::fromBase64(array.at(3).toString().toUtf8());
        QString time=QTime::currentTime().toString().remove(':');
        QString savepath=SavePixDir+time+".png";
        QFile file(savepath);
        file.open(QFile::WriteOnly);
        file.write(pixbytes);
        file.close();
        array.replace(3,savepath);
        }
        emit isFindfriendReslute(array);
        return;
    }
    else
    {
        QString fromid=array.at(1).toString();
        QString time=array.last().toString();
        qDebug()<<"fromid:"<<fromid<<time;

        if(type=="addfriendrequest")
        {
            qDebug()<<"type==addfriendrequest";
            QString pixstr=array.at(4).toString();
            qDebug()<<pixstr;
            QByteArray pix=QByteArray::fromBase64(pixstr.toUtf8());
            qDebug()<<pix.size();
            QString filepath=friendpixmap+fromid+".png";
            qDebug()<<"pixpath:"<<filepath;
            QFile file(filepath);
            file.open(QFile::WriteOnly);
            file.write(pix);
            file.close();
            QString friendname=array.at(3).toString();
            emit isaAddfriendrequest(fromid,friendname,filepath,time);

            otherRequestme.push_back(array);
            return;
        }
        else if(type=="addfriendanswer")
        {
            qDebug()<<"type==addfriendanswer";
            QString name=array.at(3).toString();
            qDebug()<<name;
            QString pixstr=array.at(4).toString();
            QByteArray pix=QByteArray::fromBase64(pixstr.toUtf8());
            QString filepath=friendpixmap+fromid+".png";


            QFile file(filepath);
            file.open(QFile::WriteOnly);
            file.write(pix);
            file.close();
            //meRequestother->remove(fromid);

            qDebug()<<"1";

            QJsonArray savearray;
            savearray.push_back(name);
            savearray.push_back(pixstr);
            friendsobject.insert(fromid,savearray);

            qDebug()<<"2";

            QJsonArray* nullarray=new QJsonArray();
            messagerecord->insert(fromid,nullarray);
            qDebug()<<"3";

            emit isaAddfriendanswer(fromid,name,filepath,time);
            return;
        }
        else
        {
            qDebug()<<"apixORmessageOrfile";
            if(type=="amessage")
            {
                QString message=array.at(3).toString();
                emit aMessage(fromid,message,time);
            }
            else if(type=="afile")
            {
                QString key=array.at(3).toString();
                QString filename=array.at(4).toString();
                double filesize=array.at(5).toDouble();
                emit aFile(fromid,key,filesize,filename,time);
            }

            else if(type=="apix")
            {
                QByteArray bytes=QByteArray::fromBase64(array.at(3).toString().toUtf8());
                QString suffix=array.at(4).toString();

                QString t=time.remove(':');
                QString savepath=SavePixDir+t+"."+suffix;
                QFile file(savepath);
                file.open(QFile::WriteOnly);
                file.write(bytes);
                file.close();
                emit aPixmap(fromid,savepath,array.last().toString());
            }
            messagerecord->find(fromid).value()->push_back(array);
            return;
        }
    }
}





void PasureMessage::PasureaMessage(QByteArray bytes)//解析一条得到的消息
{
    qDebug()<<"PasureMessage::PasureaMessage(QByteArray bytes)//解析一条得到的消息";
    QJsonDocument doc=QJsonDocument::fromJson(bytes);
    QJsonArray array(doc.array());
    PasureanotGetmessage(array);
    qDebug()<<"PasureMessage::PasureaMessage(QByteArray bytes)over";
}


void PasureMessage::PasureasendMessage(QString toid,QJsonArray array)
{
    qDebug()<<"PasureMessage::PasureasendMessage(QString toid,QJsonArray array)"<<toid;
    QString type=array.at(0).toString();
    qDebug()<<type;
    if(type=="addfriendrequest")
    {
        qDebug()<<"meRequestother->insert(toid,array)";
    }
    else if(type=="addfriendanswer")
    {
        qDebug()<<"otherRequestme->remove(toid)";
        QJsonArray::Iterator i=otherRequestme.begin();
        int x=0;
        while(i!=otherRequestme.end())
        {
            if(i->toArray().at(1).toString()==toid)
            {
                qDebug()<<"removerthis";
                otherRequestme.removeAt(x);
                break;
            }
            ++i;
            ++x;
        }
    }
    else
        messagerecord->find(toid).value()->push_back(array);

    emit sendaMessage(array);
}
