#ifndef ADDFRIENDWIDGET_H
#define ADDFRIENDWIDGET_H

#include <QJsonArray>
#include <QWidget>

namespace Ui {
class AddFriendWidget;
}

class AddFriendWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddFriendWidget(QString friendpixmapDir,QString id, QString name, QWidget *parent = nullptr);
    ~AddFriendWidget();
signals:
    void FindFriend(QString friendid);
    void addaFriend(QString friendid,QJsonArray array);

public slots:
    void GetFindReslute(QJsonArray array);
private slots:
    void on_FindButton_clicked();

    void AddThisFriend(QString friendid);
private:
    Ui::AddFriendWidget *ui;
    QString id;
    QString name;
    int x=0;

    QString friendpixmapDir;
};

#endif // ADDFRIENDWIDGET_H
