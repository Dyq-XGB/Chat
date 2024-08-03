#ifndef PASUREMESSAGE_H
#define PASUREMESSAGE_H

#include <QJsonArray>
#include <QJsonObject>
#include <QObject>

class PasureMessage : public QObject
{
    Q_OBJECT
public:
    explicit PasureMessage(QString SavePxiDir,QString clientInfoDir, QString friendpixmap,
                           QString id,QJsonObject &Baseinfoobject, QJsonObject &Friendsobject,
                           QJsonArray &Messageitemarray, QJsonArray &OtherRequestme,
                           QMap<QString, QJsonArray *> *Messagerecord,QObject *parent = nullptr);
    ~PasureMessage();

public slots:
    void PasureaMessage(QByteArray bytes);

    void PasureasendMessage(QString toid, QJsonArray array);

    void PrepareAllinfo();

    void PasureNotgetmessage(QByteArray bytes);

    void PasureanotGetmessage(QJsonArray array);

signals:
    void aMessage(QString friendid,QString message,QString time);

    void aPixmap(QString friendid,QString pixsavepath,QString time);

    void aFile(QString friendid,QString key,double filesize,QString filename,QString time);

    void isFindfriendReslute(QJsonArray array);
    void isaAddfriendrequest(QString friendid,QString friendname,QString pixpath,QString time);
    void isaAddfriendanswer(QString friendid,QString friendname,QString pixpath,QString time);

signals:
    void isNeedGetAllInfo(bool answer);
signals:
    void TheMessageitem();//QJsonArray*messageitem);
    void TheFrienditem();//QJsonObject*friendobject);
    void TheBaseInfo();//QJsonObject* baseinfoobject);
   // void TheMessagerecord();//QMap<QString,QJsonArray*>*messagerecord);
    void TheOtherRequestAdd();//QJsonArray*request);

signals:
    void sendaMessage(QJsonArray array);

    void SaveAllinfoOk();
private:
    QString SavePixDir;

    QString clientInfoDir;

    QString friendpixmap;


/*          addfriendanswer
addfriendanswer:[type,fromid,toid,fromname,pixstr,time]


            addfriendrequest
addfriendrequest:[type,fromid,toid,fromname,pixstr,time]
*/



    QJsonObject& baseinfoobject;//
/*
baseinfo:
{
createtime:str
id:str
nickname:str
headshot:str //将QBytearray转成base64 用字符串存储图片数据
}
*/
    QJsonObject& friendsobject;
/*
friends:
{
friendid:[nickname,pix]
}
*/
    QJsonArray& messageitemarray;
/*
messageitem:[friendid,friendid2,...];
*/
    QJsonArray& otherRequestme;//别人请求我
/*
otherRequestme:
{
friendid:[name,pix];
}
*/
//    QJsonObject*meRequestother;//我请求别人
///*
//meRequestother:
//{
//friendid:[name,pix];
//}
//*/
    QMap<QString,QJsonArray*>* messagerecord;
/*
messagerecord:
{
friendid:[
[type,fromid,toid,message,time],amessage
[type,fromid,toid,pixstr,suffix,time],apix
[type,fromid,toid,,filename,filekey,filesize,time] afile
]
}

*/
    bool havePasureAllinfo=false;

    bool haveSendifneed=false;

    int runsize=0;

    QString Id;
};

#endif // PASUREMESSAGE_H
