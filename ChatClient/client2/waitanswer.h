#ifndef WAITANSWER_H
#define WAITANSWER_H

#include <QWidget>

namespace Ui {
class WaitAnswer;
}

class WaitAnswer : public QWidget
{
    Q_OBJECT

public:
    explicit WaitAnswer(QString friendid, QString friendname, QString pixpath, QString time, QWidget *parent = nullptr);
    ~WaitAnswer();

private slots:
    void on_ok_clicked();
signals:
    void answerThisFriend(QString friendid,QString friendname,QString pixpath);
private:
    QString friendid;
    QString friendname;
    QString pixpath;
    Ui::WaitAnswer *ui;

};

#endif // WAITANSWER_H
