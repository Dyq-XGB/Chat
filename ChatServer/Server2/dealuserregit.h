#ifndef DEALUSERREGIT_H
#define DEALUSERREGIT_H


#include <QObject>
#include <QUdpSocket>
#include <QThreadPool>
#include <QRunnable>
class GetRegitInfomtion : public QObject
{
    Q_OBJECT
public:
    explicit GetRegitInfomtion(QObject *parent = nullptr);
    ~GetRegitInfomtion();
public slots:
    void startwork(QHostAddress ip);
    void SendReslute(QString id,QHostAddress ip,unsigned short port);
private slots:
    void GetInfomation();


signals:
    void RegitInfomation(QByteArray bytes,QHostAddress ip,unsigned short port);
    void saveThisinfo(QString info);
private:
    unsigned short Port=10002;
    QUdpSocket*udp;
};

class DealUserRegit : public QObject
{
    Q_OBJECT
public://;
    explicit DealUserRegit(QString alluserinfoDir,QMap<QString,QString>*AllidAndpassword,QMap<QString,QPair<QString,QString>>*baseinfo,
                           QMap<QString,QMap<QString,QJsonArray>*>* AllNotGetMessaeg, QObject *parent = nullptr);
    ~DealUserRegit();
public slots:
    void startwork(QHostAddress ip);
    void DealregitInfomation(QByteArray bytes,QHostAddress ip,unsigned short port);
signals:
    void startdo(QHostAddress ip);

    void saveThisinfo(QString info);

    void SendIdToUser(QString id,QHostAddress ip,unsigned short port);
private:
    QString CreateaUser(QString nickname, QString password, QString pixstr);
    bool isExist(QString&id);
private:
    QMap<QString,QString>*AllidAndpassword;
    QMap<QString,QPair<QString,QString>>*baseinfo;//id name pix

    QMap<QString,QMap<QString,QJsonArray>*>* AllNotGetMessaeg;

    QString AllUserInfoFileDir;          //服务器保存用户数据的目录2

    QString userBaseInfoPath;


    GetRegitInfomtion*getinfo;
    QThread*GetInfoThread;
};



#endif // DEALUSERREGIT_H
