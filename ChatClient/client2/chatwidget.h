#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include "amessagewidget.h"
#include <QJsonArray>
#include <QWidget>

namespace Ui {
class ChatWidget;
}



class ChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWidget(QString friendpixmap,QString SavepixDir,QString SavefileDir,QString friendid,QString friendname,
                        QString myid, QJsonArray* array, QWidget *parent = nullptr);
    ~ChatWidget();


private slots:

    void on_send_clicked();

    void on_file_clicked();

    void on_pixmap_clicked();

    void SendaFileOk(QString key,QString filepath);
signals:
    void SendaMessage(QString friendid,QJsonArray amessage);
    void SendaFile(QString filepath,aMessagewidget*widget);
    void GetaFile(QString savefilepath,QString key,aMessagewidget*widget);
    void HaveDelete(QString friendid);
public:
    void CreateAMessageWidget(QString message, int side, QString time);

    void CreateASendFileWidget(QString filepath, QString time, int side);
    void CreateAWaitGetFileWidget(QString filename, double filesize, QString filekey, QString time, int side);

    void CreateAPixWidget(QString filepath,QString tiem,int side);


private:
    Ui::ChatWidget *ui;
    QString aMessage="amessage";
    QString aFile="afile";
    QString aPixmap="apix";
    QString myid;
    QString friendid;
    QVector<aMessagewidget*>*allmessagewidget;
    QJsonArray*allmessage;
    QString friendpixpath;
    QString mypixpath;

    QString friendpixmap;

    QString SavepixDir;
    QString SavefileDir;



    // QWidget interface
protected:
    virtual void closeEvent(QCloseEvent *event) override;
};



#endif // CHATWIDGET_H
