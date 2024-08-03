#ifndef MESSAGEITEM_H
#define MESSAGEITEM_H

#include <QWidget>

namespace Ui {
class MessageItem;
}

class MessageItem : public QWidget
{
    Q_OBJECT

public:
    explicit MessageItem(QString friendid,QString name,QString pixpath,QJsonArray* messagerecord,QWidget *parent = nullptr);
    ~MessageItem();

public:
    void changelastmessage(QString lastmessage, QString lastmessagetime, bool chatwidgetIsexits);
    void changename(QString& name);

    void clearNotSeemessage();


    QString friendid;
    QString name;
    QJsonArray* messagerecord;
    int number=0;
private:
    Ui::MessageItem *ui;
};





#endif // MESSAGEITEM_H
