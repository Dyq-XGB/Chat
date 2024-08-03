#ifndef REGITDIALOG_H
#define REGITDIALOG_H

#include <QDialog>
#include <QUdpSocket>
namespace Ui {
class RegitDialog;
}

class RegitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegitDialog(QHostAddress Serverip,QString SavepixDir,QWidget *parent = nullptr);
    ~RegitDialog();

private slots:
    void on_pushButton_clicked();
    void GetId();
    void on_pushButton_2_clicked();

private:
    Ui::RegitDialog *ui;
private:
    unsigned short port=10020;
    unsigned short regitport=10002;
    QHostAddress serverip;
    QUdpSocket*udp;
    QString SavepixDir;
    QString havesavepath;
    // QObject interface
public:
    virtual bool eventFilter(QObject *watched, QEvent *event) override;
};



#endif // REGITDIALOG_H
