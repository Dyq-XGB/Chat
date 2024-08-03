#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include <QDir>
#include <QDir>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setApplicationName("slimchat");
    a.setApplicationVersion("2024.3.19");


//    static QHostAddress serverip=QHostAddress("60.205.233.74");

    QString dirpath=QCoreApplication::applicationDirPath();
    qDebug()<<dirpath;

    QDir appDir(dirpath);
    appDir.cdUp();
    appDir.cdUp();

    QString appdirpath=appDir.absolutePath();

    qDebug()<<appdirpath;

    if(!appDir.exists("AllPix"))
        appDir.mkdir("AllPix");

    if(!appDir.exists("clientfile"))
        appDir.mkdir("clientfile");

    if(!appDir.exists("friendpixmap"))
        appDir.mkdir("friendpixmap");

    if(!appDir.mkdir("UserInfoPath"))
        appDir.mkdir("UserInfoPath");

    if(!appDir.mkdir("AllFile"))
        appDir.mkdir("AllFile");

    QString AllFileDir=appdirpath+"/AllFile/";
    QString AllpixDir=appdirpath+"/AllPix/";
    QString friendpixmaDir=appdirpath+"/friendpixmap/";
    QString allUserinfoDir=appdirpath+"/UserInfoPath/";

    QString id;
    unsigned short port;
    int loginkey;
    QHostAddress serverip;
    int r=0;
    {
    LoginDialog login(AllpixDir);
    r=login.doLogin(id,port,loginkey,serverip);
    }

    if(r==1)
    {
        MainWindow w(serverip,AllFileDir,AllpixDir,friendpixmaDir,allUserinfoDir,id,port,loginkey);
        w.Init();
        w.show();
        return a.exec();
    }
    else
    return 0;

    return 0;
}
