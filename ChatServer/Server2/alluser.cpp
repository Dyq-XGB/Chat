#include "alluser.h"
#include <QDir>
#include <QFile>
#include <QRandomGenerator>

AllUser::AllUser(QObject *parent)
    : QObject{parent}
{
    alluser=new QMap<QString,User*>();

    QFile allidfile(AllUserIdFile);
    allidfile.open(QFile::ReadOnly);
    QJsonDocument doc=QJsonDocument::fromJson(allidfile.readAll());
    allidfile.close();
    QJsonArray idarray(doc.array());
    QJsonArray::Iterator i=idarray.begin();

    QString path1;
    QString path2;
    QString path3;
    QString path4;
    QString path5;

    while(i!=idarray.end())
    {
        QJsonObject fatherobject;

        QString id=i->toString();
        QString infoDir=AllUserInfoFileDir+id+"/";

        path1=infoDir+BASEINFOMATION;
        QFile baseinfomation(path1);
        baseinfomation.open(QFile::ReadOnly);
        QJsonDocument doc1=QJsonDocument::fromJson(baseinfomation.readAll());
        baseinfomation.close();
        QJsonObject* object1=new QJsonObject(doc1.object());

        path2=infoDir+FRIENDS;
        QFile friends(path2);
        friends.open(QFile::ReadOnly);
        QJsonDocument doc2=QJsonDocument::fromJson(friends.readAll());
        friends.close();
        QJsonObject* object2=new QJsonObject(doc2.object());

        path3=infoDir+MESSAGEITEMRECORD;
        QFile messageitemrecord(path3);
        messageitemrecord.open(QFile::ReadOnly);
        QJsonDocument doc3=QJsonDocument::fromJson(messageitemrecord.readAll());
        messageitemrecord.close();
        QJsonArray* array3=new QJsonArray(doc3.array());

        path4=infoDir+MESSAGERECORD;
        QFile messagerecord(path4);
        messagerecord.open(QFile::ReadOnly);
        QJsonDocument doc4=QJsonDocument::fromJson(messagerecord.readAll());
        messagerecord.close();
        QJsonObject object4(doc4.object());
        QMap<QString,QJsonArray*>*mr=new QMap<QString,QJsonArray*>();
        QJsonArray*messagearray;
        QJsonObject::Iterator i=object4.begin();
        while(i!=object4.end())
        {
            messagearray=new QJsonArray(i.value().toArray());
            mr->insert(i.key(),messagearray);
            ++i;
        }

        path5=infoDir+NOTGETMESSAGE;
        QFile notgetmessage(path5);
        notgetmessage.open(QFile::ReadOnly);
        QJsonDocument doc5=QJsonDocument::fromJson(notgetmessage.readAll());
        notgetmessage.close();
        QJsonObject object5(doc5.object());
        QMap<QString,QJsonArray*>*ngm=new QMap<QString,QJsonArray*>();
        QJsonArray*notgetmessagearray;
        QJsonObject::Iterator ni=object5.begin();
        while(ni!=object5.end())
        {
            notgetmessagearray=new QJsonArray(ni.value().toArray());
            ngm->insert(ni.key(),notgetmessagearray);
            ++ni;
        }

        User*u=new User(id,object1,object2,array3,mr,ngm,path1,path2,path3,path4,path5);
        alluser->insert(id,u);
    }
}

AllUser::~AllUser()
{
    QString id;
    for(auto&i:*alluser)
    {
        id=i->getID();
        delete i;
        alluser->remove(id);
    }
    delete alluser;
}

QString AllUser::CreateaUser(QString &Password)
{
    QString Id;
    do
    {
        Id=QString::number(QRandomGenerator::global()->bounded(100000,999999));
    }while(isExist(Id));

    QDir dir(AllUserInfoFileDir);
    dir.mkdir(Id);
    QString infomationdir=AllUserInfoFileDir+Id+"/";
    QString createtime=QDate::currentDate().toString()+"+"+QTime::currentTime().toString();

    QString path1(infomationdir+BASEINFOMATION);
    QJsonObject* object1=new QJsonObject();
    object1->insert("id",Id);
    object1->insert("password",Password);
    object1->insert("createtime",createtime);
    object1->insert("nickname","企鹅");
    QJsonDocument doc1(*object1);
    QFile baseinfomation(path1);
    baseinfomation.open(QFile::WriteOnly);
    baseinfomation.write(doc1.toJson());
    baseinfomation.close();

    QString path2(infomationdir+FRIENDS);
    QJsonObject* object2=new QJsonObject();
    QJsonDocument doc2(*object2);
    QFile friends(path2);
    friends.open(QFile::WriteOnly);
    friends.write(doc2.toJson());
    friends.close();

    QString path3(infomationdir+MESSAGEITEMRECORD);
    QJsonArray* array3=new QJsonArray();
    QJsonDocument doc3(*array3);
    QFile messageitemrecord(path3);
    messageitemrecord.open(QFile::WriteOnly);
    messageitemrecord.write(doc3.toJson());
    messageitemrecord.close();

    QString path4(infomationdir+MESSAGERECORD);
    QJsonObject object4;
    QJsonDocument doc4(object4);
    QFile messagerecord(path4);
    messagerecord.open(QFile::WriteOnly);
    messagerecord.write(doc4.toJson());
    messagerecord.close();
    QMap<QString,QJsonArray*>*messagemap=new QMap<QString,QJsonArray*>();

    QString path5(infomationdir+NOTGETMESSAGE);
    QJsonObject* object5=new QJsonObject();
    QJsonDocument doc5(*object5);
    QFile notgetmessage(path5);
    notgetmessage.open(QFile::WriteOnly);
    notgetmessage.write(doc5.toJson());
    notgetmessage.close();
    QMap<QString,QJsonArray*>*notgetmessagemap=new QMap<QString,QJsonArray*>();


    User*u=new User(Id,object1,object2,array3,messagemap,notgetmessagemap,path1,path2,path3,path4,path5);
    alluser->insert(Id,u);

    qDebug()<<"CreateaUser:"<<Id;
    return Id;
}

bool AllUser::ChangePassword(QString &Id, QString &oldPassword, QString &newPassword)
{
    User* U=alluser->find(Id).value();
    bool changereslute=U->changePassword(oldPassword,newPassword);
    qDebug()<<"ChangePassword:"<<Id<<"newPassword:"<<newPassword;
    return changereslute;
}

bool AllUser::isExist(QString &Id)
{
    return alluser->contains(Id);
}

int AllUser::UserNumber()
{
    return alluser->size();
}

bool AllUser::passwordIsRight(QString &Id, QString &password)
{
    User*U=alluser->find(Id).value();
    bool isRight=U->passwordIsRight(password);
    return isRight;
}

User *AllUser::GetUser(QString &Id)
{
    return alluser->find(Id).value();
}
QJsonDocument *AllUser::GetUserNotGetMessage(QString& ID)
{
    User*U=alluser->find(ID).value();
    return U->NotGetMessage();
}

QJsonDocument *AllUser::GetUserAllInfo(QString& ID)
{
    User*U=alluser->find(ID).value();
    return U->UserAllInfo();
}

QJsonDocument *AllUser::GetUserMessageRecord(QString &id, QString &friendid)
{
    User*u=alluser->find(id).value();
    return u->MessageRecord(friendid);
}

QJsonDocument *AllUser::GetUserAllMessageRecord(QString &id)
{
    User*u=alluser->find(id).value();
    return u->AllMessageRecord();
}

QJsonDocument *AllUser::GetUserBaseInfo(QString &id)
{
    User*u=alluser->find(id).value();
    return u->BaseInfo();
}

void AllUser::updateMessageRecord(QJsonArray amessage)
{
    QString toid=amessage.at(2).toString();
    QString fromid=amessage.at(1).toString();

    User*tou=alluser->find(toid).value();
    User*fromu=alluser->find(fromid).value();

    tou->updateMessageRecord(fromid,amessage);
    fromu->updateMessageRecord(fromid,amessage);
}

void AllUser::updataNotGetMessage(QJsonArray amessage)
{
    QString toid=amessage.at(2).toString();
    QString fromid=amessage.at(1).toString();
    User*tou=alluser->find(toid).value();
    User*fromu=alluser->find(fromid).value();

    tou->updataNotGetMessage(fromid,amessage);
    tou->updateMessageRecord(fromid,amessage);
    fromu->updateMessageRecord(fromid,amessage);
}


void AllUser::updataMessageItemRecord(QString id,QJsonDocument* doc)
{
    User*u=alluser->find(id).value();
    u->updataMessageItemRecord(doc);
}

void AllUser::updataFriendID(QString id, QString friendid, QString name)
{
    User*u=alluser->find(id).value();
    u->updataFriendID(friendid,name);
}



void AllUser::updataBaseInfo(QString id, QString type, QString change)
{
    User*u=alluser->find(id).value();
    u->updatabaseinfo(type,change);
}



//============================User================================
User::User(QString id,
           QJsonObject *baseinfomation, QJsonObject *friends,
           QJsonArray *messageitemrecord, QMap<QString, QJsonArray *> *messagerecord, QMap<QString, QJsonArray *> *notgetmessage,
           QString &path1, QString &path2, QString &path3, QString &path4, QString &path5)
    :ID(id),baseinfomation(baseinfomation),friends(friends),messageitemrecord(messageitemrecord),
    messagerecord(messagerecord),notgetmessage(notgetmessage),
    baseinfomationfilepath(path1),friendsfilepath(path2),messageitemrecordfilepath(path3),
    messagerecordfilepath(path4),notgetmessagefilepath(path5)
{
    qDebug()<<"User::User"<<"NewaUser"<<"ID:"<<id;
}

User::~User()
{
    qDebug()<<"User::~User()"<<"User:"<<ID;
    QFile baseinfofile(baseinfomationfilepath);
    QJsonDocument doc1(*baseinfomation);
    baseinfofile.open(QFile::WriteOnly);
    baseinfofile.write(doc1.toJson());
    baseinfofile.close();

    QFile friendsfile(friendsfilepath);
    QJsonDocument doc2(*friends);
    baseinfofile.open(QFile::WriteOnly);
    baseinfofile.write(doc2.toJson());
    baseinfofile.close();

    QFile messageitemrecordfile(messageitemrecordfilepath);
    QJsonDocument doc3(*messageitemrecord);
    baseinfofile.open(QFile::WriteOnly);
    baseinfofile.write(doc3.toJson());
    baseinfofile.close();

    QFile messagerecordfile(messagerecordfilepath);
    QJsonObject messagerecordobject;
    QMap<QString,QJsonArray*>::Iterator i4=messagerecord->begin();
    QJsonArray*array;
    while(i4!=messagerecord->end())
    {
        array=i4.value();
        messagerecordobject.insert(i4.key(),*array);
        delete array;
        ++i4;
    }
    QJsonDocument doc4(messagerecordobject);
    messagerecordfile.open(QFile::WriteOnly);
    messagerecordfile.write(doc4.toJson());
    messagerecordfile.close();


    QFile notgetmessagefile(notgetmessagefilepath);
    QJsonObject object5;
    QMap<QString,QJsonArray*>::Iterator i5=notgetmessage->begin();
    QJsonArray* notgetarray;
    while(i5!=notgetmessage->end())
    {
        notgetarray=i5.value();
        object5.insert(i5.key(),*notgetarray);
        delete notgetarray;
        ++i5;
    }
    QJsonDocument doc5(object5);
    notgetmessagefile.open(QFile::WriteOnly);
    notgetmessagefile.write(doc5.toJson());
    notgetmessagefile.close();

    delete baseinfomation;
    delete friends;
    delete messageitemrecord;
    delete messagerecord;
    delete notgetmessage;
}


QString User::getID() const
{
    return ID;
}

bool User::changePassword(QString &oldPassword, QString &newPassword)
{
    qDebug()<<"User::changePassword(QString &oldPassword, QString &newPassword)"<<oldPassword<<newPassword;
    bool re=false;
    if(oldPassword==baseinfomation->find("password").value().toString())
    {
        baseinfomation->insert("password",newPassword);
        re=true;
    }
    qDebug()<<"User:"<<ID<<"changePasswordreslute:"<<re;
    return re;
}

void User::updateMessageRecord(QString&fromid,QJsonArray&amessage)
{
    if(fromid==ID)
        fromid=amessage.at(2).toString();
    messagerecord->find(fromid).value()->push_back(amessage);
}
void User::updataNotGetMessage(QString fromid, QJsonArray &amessage)
{
    messagerecord->find(fromid).value()->push_back(amessage);
}
void User::updataMessageItemRecord(QJsonDocument*doc)
{
    qDebug()<<"User::updataMessageItemRecord(QJsonArray*array)";
    delete messageitemrecord;
    QJsonArray*array=new QJsonArray(doc->array());
    messageitemrecord=array;
    delete doc;
}

void User::updataFriendID(QString& id, QString& name)
{
    qDebug()<<"User::updataFriendID(QString& id, QString& name)"<<id<<name;
    friends->insert(id,name);
    QJsonArray* array=new QJsonArray();
    messagerecord->insert(id,array);
}

void User::updatabaseinfo(QString &type, QString &change)
{
    qDebug()<<"User::updatabaseinfo(QString &type, QString &change)"<<type<<change;
    if(type=="nickname")
        baseinfomation->insert(type,change);
}



bool User::passwordIsRight(QString& password)
{
    qDebug()<<"passwordIsRight(QString& password)"<<password;
    QString Password=baseinfomation->find("password").value().toString();
    qDebug()<<"UserPassword:"<<Password;
    return Password==password;
}

QJsonDocument *User::NotGetMessage()
{
    qDebug()<<"User::NotGetMessage()";
    QJsonObject object;
    QMap<QString,QJsonArray*>::Iterator i=notgetmessage->begin();
    QJsonArray*array;
    while(i!=notgetmessage->end())
    {
        array=i.value();
        object.insert(i.key(),*array);
        delete array;
        ++i;
    }
    QJsonDocument*doc=new QJsonDocument(object);
    notgetmessage->clear();
    return doc;
}

QJsonDocument *User::MessageRecord(QString& friendid)
{
    qDebug()<<"MessageRecord(QString& friendid)"<<friendid;
    QJsonObject object;
    object.insert(friendid,*messagerecord->find(friendid).value());
    QJsonDocument*doc=new QJsonDocument(object);
    return doc;
}

QJsonDocument *User::AllMessageRecord()
{
    qDebug()<<"User::AllMessageRecord()";
    QJsonObject object;
    QMap<QString,QJsonArray*>::Iterator i=messagerecord->begin();
    while(i!=messagerecord->end())
    {
        object.insert(i.key(),*i.value());
        ++i;
    }
    QJsonDocument*doc=new QJsonDocument(object);
    return doc;
}

QJsonDocument *User::UserAllInfo()
{
    qDebug()<<"User::UserAllInfo()";
    QJsonObject fatherobject;
    fatherobject.insert("baseinfomation",*baseinfomation);
    fatherobject.insert("friends",*friends);
    fatherobject.insert("messageitemrecord",*messageitemrecord);

    QMap<QString,QJsonArray*>::Iterator i1=messagerecord->begin();
    QJsonObject messager;
    while(i1!=messagerecord->end())
    {
        messager.insert(i1.key(),*i1.value());
        ++i1;
    }
    fatherobject.insert("messagerecord",messager);

    QMap<QString,QJsonArray*>::Iterator i2=notgetmessage->begin();
    QJsonObject notmessager;
    while(i2!=notgetmessage->end())
    {
        notmessager.insert(i1.key(),*i2.value());
        ++i2;
    }
    fatherobject.insert("notgetmessage",notmessager);

    QJsonDocument* doc=new QJsonDocument(fatherobject);
    return doc;
}

QJsonDocument *User::BaseInfo()
{
    qDebug()<<"User::BaseInfo()";
    QJsonDocument*doc=new QJsonDocument(*baseinfomation);
    return doc;
}
