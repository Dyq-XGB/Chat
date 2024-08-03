#ifndef DEALFILE_H
#define DEALFILE_H

#include <QTcpSocket>
#include <QObject>
#include <QRunnable>
#include <QTcpServer>
#include <QUdpSocket>
#include <QVector>
#include <QFile>
#include <QDataStream>
#include <QMap>
#include <QThreadPool>
#include <QReadWriteLock>
#include "myserver.h"

class FileLib : public QObject
{
    Q_OBJECT
public:
    explicit FileLib(QString allfileinfoDir,QObject *parent = nullptr);
    virtual ~FileLib();
public:
    QString GetaNotUseKey();
    void AddIntoFileLib(QString key, QJsonArray *array);
    QJsonArray *GetaFile(QString key);
    bool isExits(QString&key);
private:
    QString CreateaKey();

private:
    QString FilelibDir;
    QString FilekeyAndInfoPath;
    QVector<QString>*notuseKey;
    QMap<QString,QJsonArray*>*keyAndfileinfo;
};




class aget :public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit aget(QString allFileDir,FileLib*filelib,qintptr handle,QObject *parent = nullptr);
    ~aget();
signals:
    void afileGetState(QString key,bool state);

    void saveThisinfo(QString info);
private:
    QString success="success";
    QString faile="faile";
    QString SaveFileDir;
    qintptr handle;
    QTcpSocket*socket;
    FileLib*filelib;
    double haveGet=0;
    // QRunnable interface
public:
    virtual void run() override;
};

class GetFile : public QObject
{
    Q_OBJECT
public:
    explicit GetFile(QString filedir,FileLib*filelib,
                     QObject *parent = nullptr);
    virtual ~GetFile();

public slots:
    void startdo(QHostAddress ip);
signals:
    void saveThisinfo(QString info);
private slots:
    void GetaFile(qintptr handle);
private:
    unsigned short port=10018;
    QString Filedir;
    QThreadPool*getfilepool;
    Myserver*get_server;
    FileLib*filelib;
};


class asend : public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit asend(QString allfileDir,FileLib*filelib,qintptr handle,QObject *parent = nullptr);
    ~asend();
signals:
    void saveThisinfo(QString info);
private:
    int asize=4*1024;
    QString FileDir;
    qintptr handle;
    QTcpSocket*socket;
    FileLib*filelib;
    // QRunnable interface
public:
    virtual void run() override;
};

class SendFile : public QObject
{
    Q_OBJECT
public:
    explicit SendFile(QString filedir,FileLib*filelib,QObject *parent = nullptr);
    virtual ~SendFile();
public slots:
    void startdo(QHostAddress ip);
private slots:
    void SendaFile(qintptr handle);
signals:
    void saveThisinfo(QString info);
private:
    FileLib*filelib;
    QString fileDir;
    unsigned short port=10019;
    Myserver* send_server;
    QThreadPool* sendpool;
};

class DealFile : public QObject
{
    Q_OBJECT
public:
    explicit DealFile(QString allfileDir,QObject *parent = nullptr);
    virtual ~DealFile();
public slots:
    void startwork(QHostAddress ip);
signals:
    void start(QHostAddress ip);

    void saveThisinfo(QString info);
private:

    QString fileDir;

    FileLib*filelib;
    GetFile*get;
    SendFile*send;

    QThread*get_t;
    QThread*send_t;
};




#endif // DEALFILE_H
