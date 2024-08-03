#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "allworker.h"
#include "onlineuser.h"
#include <QMainWindow>
class DealUserRegit;
class DealUserLogin;
class DealUserConnect;
class DealFile;
class DealMessage;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void deleteAllok();

    void aOnline(QString id, QHostAddress ip, unsigned short port, QString time);
    void adeLine(QString id, QString time);

public:
    MainWindow(QString logfilepath, QString AlluserInfoDir, QString AllFileDir, QString Alluserinfopath, QString Allfileinfopath, QString AllserverPath, QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void start(QHostAddress ip);

private slots:
    void on_startlisen_clicked();

    void saveThisinfo(QString message);
private:
    bool needClose=false;

    QString alluserinfoDir;
    QString alluserbaseinfoPath;

    QString allfileinfoDir;
    QString allfielinfoPath;


    QString allserverDir;

    QMap<QString,QString>*AllidAndpassword;
    QMap<QString,QPair<QString,QString>>*baseinfo;


    QMap<int,QString>*AllwaitConnect;

    QMap<QString,QMap<QString,QJsonArray>*>*AllNotGetMessaeg;

    AllOnlineUser*onlineusers;
    QThread*online_t;

    DealUserLogin*dealLogin;
    QThread*Login_t;

    DealUserRegit*dealRegit;
    QThread*Regit_t;

    DealUserConnect*Dealconnect;
    QThread*connect_t;

    DealFile*file;
    QThread* file_t;

    DealMessage*Dealmessage;
    QThread* message_t;


    DealAddFriend*Dealaddfriend;
    QThread* add_t;

    QFile* logfile;
    QString logFilepath;


    bool haveInit=false;

private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
