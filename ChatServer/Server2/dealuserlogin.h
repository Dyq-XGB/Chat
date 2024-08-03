#ifndef DEALUSERLOGIN_H
#define DEALUSERLOGIN_H


#include <QThreadPool>
#include <QObject>
#include <QRunnable>
#include <QUdpSocket>



class GetLoginInfomation : public QObject
{
    Q_OBJECT
public:
    explicit GetLoginInfomation(QObject *parent = nullptr);
    virtual ~GetLoginInfomation();
public slots:
    void startwork(QHostAddress ip);

    void SendResluteToUser(QByteArray bytes,QHostAddress ip,unsigned short port);
private slots:
    void GetInfo();
signals:
    void LoginInfomation(QByteArray bytes,QHostAddress ip,unsigned short port);

    void saveThisinfo(QString info);
private:
    QUdpSocket*udp;
    unsigned short Port=10005;
};



class DealUserLogin : public QObject
{
    Q_OBJECT
public:
    explicit DealUserLogin(QMap<QString,QString>*AllidAndpassword,
                           QMap<int,QString>*AllwaitConnect,QObject *parent = nullptr);
    virtual ~DealUserLogin();
public slots:
    void startwork(QHostAddress ip);
private slots:
    void DealLoginInfomation(QByteArray bytes, QHostAddress ip, unsigned short port);
signals:
    void dowork(QHostAddress ip);

    void saveThisinfo(QString info);

    void SendLoginResluteToUser(QByteArray bytes,QHostAddress ip,unsigned short port);
private:
    bool isRight(QString& id,QString& password);
private:

    QMap<QString,QString>*AllidAndpassword;
    QMap<int,QString>*AllwaitConnect;
    GetLoginInfomation*getinfo;

    QThread*getInfomationThread;
};

#endif // DEALUSERLOGIN_H
