#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QUdpSocket>
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QString savepixdir, QWidget *parent = nullptr);
    ~LoginDialog();
public:
    int doLogin(QString&Id, unsigned short&Port, int &LoginKey, QHostAddress &serverip);
private slots:
    void on_Regit_clicked();
    void on_Login_clicked();
    void GetCheckReslute();
private:
    Ui::LoginDialog *ui;
private:
    QUdpSocket*udp;
    unsigned short port=10021;
    unsigned short loginport=10005;
    QHostAddress serverip;
    int loginKey;
    QString id;
    QString savepixdir;
};

#endif // LOGINDIALOG_H
