#ifndef ALLUSER_H
#define ALLUSER_H

#include <QObject>
#include <QVector>
#include <QTime>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "qfile.h"

class User
{
public:
    // User(QString id,QJsonDocument*doc,QMap<QString,QString>*baseinfomation,QMap<QString,QString>*friends,
    //      QVector<QPair<QString,QString>>*messageitemrecord,QMap<QString,QJsonArray*>*messagerecord,QMap<QString,QJsonArray*>*notgetmessage
    //      ,QString& path1,QString& path2,QString& path3,QString& path4,QString& path5);
    User(QString id,
         QJsonObject*baseinfomation,QJsonObject*friends,QJsonArray*messageitemrecord,
         QMap<QString,QJsonArray*>*messagerecord,QMap<QString,QJsonArray*>*notgetmessage,
         QString& path1,QString& path2,QString& path3,QString& path4,QString& path5);
    ~User();
public:
    QString getID() const;


    void updateMessageRecord(QString &fromid, QJsonArray &amessage);
    void updataNotGetMessage(QString fromid, QJsonArray&amessage);
    bool changePassword(QString& oldPassword,QString& newPassword);
    void updataMessageItemRecord(QJsonDocument *doc);
    void updataFriendID(QString& id, QString& name);
    void updatabaseinfo(QString&type,QString&change);
    bool passwordIsRight(QString &password);



    QJsonDocument* NotGetMessage();
    QJsonDocument* MessageRecord(QString& friendid);//暂时不解决按时间获取消息记录
    QJsonDocument* AllMessageRecord();
    QJsonDocument* UserAllInfo();
    QJsonDocument* BaseInfo();

private:
    QString ID;
    QJsonDocument* userallinfo;

    // QMap<QString,QString>* baseinfomation;
    // QMap<QString,QString>* friends;
    // QVector<QPair<QString,QString>>* messageitemrecord;
    QJsonObject*baseinfomation;
    QJsonObject*friends;
    QJsonArray*messageitemrecord;
    QMap<QString,QJsonArray*>*messagerecord;
    QMap<QString,QJsonArray*>*notgetmessage;

    QString baseinfomationfilepath;
    QString friendsfilepath;
    QString messageitemrecordfilepath;
    QString messagerecordfilepath;
    QString notgetmessagefilepath;
};


class AllUser : public QObject
{
    Q_OBJECT
public:
    explicit AllUser(QObject *parent = nullptr);
    ~AllUser();
public:
    QString CreateaUser(QString& Password);//√ 创建一个新的用户
    bool ChangePassword(QString& Id, QString& oldPassword, QString& newPassword);//√ 为用户更改密码
    bool isExist(QString& Id);//√ 判断用户是否存在
    int UserNumber();//√  返回用户数量
    bool passwordIsRight(QString& Id,QString& password);//√  判断密码是否正确
    User* GetUser(QString& Id);//√  当用户登录后 返回用户给Onlineuser操作

    QJsonDocument* GetUserNotGetMessage(QString& ID);//√  返回用户离线时间没有得到的消息
    QJsonDocument* GetUserAllInfo(QString& ID);//√  返回用户所有的信息
    QJsonDocument* GetUserMessageRecord(QString&id, QString& friendid);//返回用户指定好友的聊天记录
    QJsonDocument* GetUserAllMessageRecord(QString&id);//返回用户所有的聊天记录
    QJsonDocument* GetUserBaseInfo(QString&id);//返回用户基本信息
public slots:
    void updateMessageRecord(QJsonArray amessage);//更新消息记录
    void updataMessageItemRecord(QString id, QJsonDocument *doc);//更新聊天界面记录
    void updataFriendID(QString id, QString friendid, QString name);//更新好友记录
    void updataNotGetMessage(QJsonArray amessage);//更新没有得到的信息记录
    void updataBaseInfo(QString id,QString type,QString change);//更新基本信息
signals:
private:
    QJsonObject *CreateaUserJson(QFile& file, QString &id, QString &password);
private:
    QString AllUserInfoFileDir="D:/QQApp2/newServer/AllUserInfo/";          //服务器保存用户数据的目录
    QString AllUserIdFile="D:/QQApp2/newServer/AllUserInfo/ids.json";       //用户id文件

        //信息文件后缀
    QString BASEINFOMATION="baseinfomation.json";
    QString FRIENDS="friends.json";
    QString MESSAGEITEMRECORD="messageitemrecord.json";
    QString MESSAGERECORD="messagerecord.json";
    QString NOTGETMESSAGE="notgetmessage.json";

    QMap<QString,User*> *alluser;
};

#endif // ALLUSER_H
