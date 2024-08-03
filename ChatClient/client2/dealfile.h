#ifndef DEALFILE_H
#define DEALFILE_H


#include "amessagewidget.h"
#include <QTcpSocket>
#include <QObject>
#include <QUdpSocket>
#include <QRunnable>
#include <QTcpServer>
#include <QThreadPool>
#include <QQueue>
class asend :public QObject,public QRunnable
{
    Q_OBJECT

public:
    explicit asend(QHostAddress serverip,QString filepath,aMessagewidget*widget,QObject *parent = nullptr);
    ~asend();
public slots:
    void Stopsend();
signals:
    void sendFileSuccess(QString key);
    void sendFileFaile();
    void sendAsize(int size);

private:
    int areadsize=50*1024;
    QString success="success";
    QString faile="faile";
    QString filepath;
    aMessagewidget*widget;
    QTcpSocket*socket;
    QHostAddress serverip;
    unsigned short serverGetFileport=10018;

    bool send=true;
    // QRunnable interface
public:
    virtual void run() override;
};


class aget :public QObject,public QRunnable
{
    Q_OBJECT

public:
    explicit aget(QHostAddress serverip,QString savefilepath,QString key,aMessagewidget*widget,QObject *parent = nullptr);
    ~aget();
signals:
    void getFileSuccess();
    void getFileFaile();
    void getAsize(int size);
private:
    QString savefilepath;
    QString key;
    aMessagewidget*widget;
    QTcpSocket*socket;
    QHostAddress serverip;
    unsigned short serverSendFileport=10019;
    // QRunnable interface
public:
    virtual void run() override;
};



class DealFile : public QObject
{
    Q_OBJECT

public:
    explicit DealFile(QHostAddress serverip,QObject *parent = nullptr);
    ~DealFile();
public slots:
    void startwork();
    void GetaFile(QString savefilepath,QString key,aMessagewidget*widget);
    void SendaFile(QString filepath, aMessagewidget *widget);
signals:

    void SendaFileOk(QJsonArray*array);
    void SendaFileError(QJsonArray*array);

    void GetaFileOk(QString key);//发给界面更新界面
    void aFileGetError(QString key);

    void startGetaFile();
private:
    QThreadPool*t_pool;

    QHostAddress serverip;
};





#endif // DEALFILE_H
