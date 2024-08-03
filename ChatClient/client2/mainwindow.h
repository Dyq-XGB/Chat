#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidgetItem>
#include <QMainWindow>
#include <QTcpSocket>
#include <QUdpSocket>
#include "addfriendwidget.h"
#include "chatwidget.h"
#include "connecttoserver.h"
#include "dealfile.h"
#include "dealmessage.h"
#include "frienditem.h"
#include "messageitem.h"
#include "pasuremessage.h"
#include "waitanswer.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QHostAddress Serverip, QString AllFileDir, QString AllpixDir, QString friendpixmaDir, QString allUserinfoDir, QString id, unsigned short port, int Loginkey, QWidget *parent = nullptr);
    ~MainWindow();
public:
    void Init();
private slots:
    void on_MessageList_itemDoubleClicked(QListWidgetItem *item);

    void on_FriendList_itemDoubleClicked(QListWidgetItem *item);

    void removeaChatWidget(QString friendid);

    void on_addFriend_clicked();

    void do_addThisFriend(QString friendid, QString friendname, QString pixpath);
public slots:
    void DeleteAll();
public slots:

    void aMessage(QString friendid, QString message, QString time);

    void aFile(QString friendid,QString key,double filesize,QString filename,QString time);
    void aPixmap(QString friendid,QString pixsavepath,QString time);

    void aAddfriendanswer(QString friendid, QString friendname, QString pixpath);
    void aAddfriendrequest(QString friendid,QString friendname,QString pixpath,QString time);

    void setBaseinfo();//QJsonObject *object);
    //void setMessagereocrd();//QMap<QString, QJsonArray*> *allrecord);
    void setFriendItem();//QJsonObject *object);
    void setMessageItem();//QJsonArray *array);
    void setOtherRequestAdd();//QJsonArray *array);

public slots:
    void CreateaChatWidget(QString friendid, QString friendname, QJsonArray *messagerecord);
private:
    void addAMessageitem(QString friendid);
    void addAFrienditem(QString friendid, QString friendname, QString pixpath);

signals:
    void signal_start_connectToServer(int Loginkey,unsigned short port,bool needGetAllinfo);
    void startwork();
    void sendAmessage(QJsonArray amessage);

    void HaveaFindWidget(AddFriendWidget*addwidget);


    void answerThisFriend(QString firendid,QJsonArray array);

    void startPasure(QString id,QJsonObject& baseinfoobject,
                     QJsonObject& friendsobject,
                     QJsonArray& messageitemarray,
                     QJsonArray&otherRequestme,
                     QMap<QString,QJsonArray*>* messagerecord);


    void StopGetMessage();

    void SendInfoToServer();
private:
    Ui::MainWindow *ui;
private:/*
    QSize minsize=QSize(320,400);
    QSize maxsize=QSize(320,760);*/

    bool needClose=false;

    QString id;
    QString name;
    unsigned short port;
    int Loginkey;

    QHostAddress Serverip;
    QString AllFileDir;
    QString AllpixDir;
    QString friendpixmaDir;
    QString allUserinfoDir;
    QString friendpixmapDir;
    QString savepixDir;
    QString savefileDir;



    QMap<QString,MessageItem*>*allmessageitem;

    QMap<QString,Frienditem*>*allfriendwidget;

    QMap<QString,ChatWidget*>*allchatwidget;

    QMap<QString,WaitAnswer*>*allwaitanswer;

    AddFriendWidget*findfriendwidget;

    QJsonObject baseinfoobject;
    QJsonObject friendsobject;
    QJsonArray messageitemarray;
    QJsonArray otherRequestme;
    QMap<QString,QJsonArray*>* messagerecord;

    ConnectToServer*con;
    QThread* t_con;

    PasureMessage*pasure;
    QThread* p_t;

    DealFile*file;
    QThread*t_f;

    DealMessage*message;
    QThread*m_t;

protected:
    virtual void closeEvent(QCloseEvent *event) override;
};





#endif // MAINWINDOW_H
