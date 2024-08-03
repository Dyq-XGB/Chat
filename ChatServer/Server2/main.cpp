#include "mainwindow.h"
#include "qdir.h"

#include <QApplication>
#include <QJsonDocument>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDir dir(a.applicationDirPath());
//    dir.cdUp();
//    dir.cdUp();
    QString dirpath=dir.absolutePath();



    QString AllfileDir=dirpath+"/AllFile/";

    QString AllfileInfopath=AllfileDir+"keyAndinfo.json";

    QString AlluserinfoDir=dirpath+"/AllUserInfo/";

    QString AlluserInfopath=AlluserinfoDir+"AllUserBaseInfo.json";

    QString serverfileDir=dirpath+"/ServerFile/";

    QString logFilepath=dirpath+"/log.txt";

    qDebug()<<logFilepath;

    if(!dir.exists("AllFile"))
    {
        dir.mkdir("AllFile");
        QFile allfileinfoFile(AllfileInfopath);
        QJsonObject object;
        QJsonDocument doc(object);
        allfileinfoFile.open(QFile::WriteOnly);
        allfileinfoFile.write(doc.toJson());
        allfileinfoFile.close();
    }
    if(!dir.exists("AllUserInfo"))
    {
        dir.mkdir("AllUserInfo");
        QFile alluserinfoFile(AlluserInfopath);
        QJsonObject object;
        QJsonDocument doc(object);
        alluserinfoFile.open(QFile::WriteOnly);
        alluserinfoFile.write(doc.toJson());
        alluserinfoFile.close();
    }
    if(!dir.exists("ServerFile"))
    {
        dir.mkdir("ServerFile");
    }

    if(!dir.exists("log.txt"))
    {
        QFile file(logFilepath);
        file.open(QFile::WriteOnly);
        file.write(QString("==================================log=================================").toUtf8());
        file.close();
    }

    MainWindow* w=new MainWindow(logFilepath,AlluserinfoDir,AllfileDir,AlluserInfopath,AllfileInfopath,serverfileDir);
    w->show();
    return a.exec();
}
