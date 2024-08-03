/********************************************************************************
** Form generated from reading UI file 'messageitem.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEITEM_H
#define UI_MESSAGEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageItem
{
public:
    QLabel *headshot;
    QLabel *message;
    QLabel *nickname;
    QLabel *time;
    QLabel *NotGetMessageNumber;

    void setupUi(QWidget *MessageItem)
    {
        if (MessageItem->objectName().isEmpty())
            MessageItem->setObjectName("MessageItem");
        MessageItem->resize(287, 60);
        MessageItem->setMinimumSize(QSize(250, 60));
        MessageItem->setMaximumSize(QSize(330, 60));
        headshot = new QLabel(MessageItem);
        headshot->setObjectName("headshot");
        headshot->setGeometry(QRect(10, 0, 50, 50));
        headshot->setMinimumSize(QSize(50, 50));
        headshot->setMaximumSize(QSize(50, 50));
        headshot->setAlignment(Qt::AlignCenter);
        message = new QLabel(MessageItem);
        message->setObjectName("message");
        message->setGeometry(QRect(50, 30, 190, 25));
        message->setMinimumSize(QSize(190, 25));
        message->setMaximumSize(QSize(190, 25));
        nickname = new QLabel(MessageItem);
        nickname->setObjectName("nickname");
        nickname->setGeometry(QRect(70, 10, 100, 25));
        nickname->setMinimumSize(QSize(100, 25));
        nickname->setMaximumSize(QSize(100, 25));
        time = new QLabel(MessageItem);
        time->setObjectName("time");
        time->setGeometry(QRect(180, 10, 50, 25));
        time->setMinimumSize(QSize(50, 25));
        time->setMaximumSize(QSize(50, 15));
        time->setAlignment(Qt::AlignCenter);
        NotGetMessageNumber = new QLabel(MessageItem);
        NotGetMessageNumber->setObjectName("NotGetMessageNumber");
        NotGetMessageNumber->setGeometry(QRect(230, 20, 50, 25));
        NotGetMessageNumber->setMinimumSize(QSize(50, 25));
        NotGetMessageNumber->setMaximumSize(QSize(50, 25));
        NotGetMessageNumber->setAlignment(Qt::AlignCenter);

        retranslateUi(MessageItem);

        QMetaObject::connectSlotsByName(MessageItem);
    } // setupUi

    void retranslateUi(QWidget *MessageItem)
    {
        MessageItem->setWindowTitle(QCoreApplication::translate("MessageItem", "Form", nullptr));
        headshot->setText(QCoreApplication::translate("MessageItem", "\345\244\264\345\203\217", nullptr));
        message->setText(QCoreApplication::translate("MessageItem", "\344\277\241\346\201\257", nullptr));
        nickname->setText(QCoreApplication::translate("MessageItem", "\346\230\265\347\247\260", nullptr));
        time->setText(QCoreApplication::translate("MessageItem", "\346\227\266\351\227\264", nullptr));
        NotGetMessageNumber->setText(QCoreApplication::translate("MessageItem", "\346\225\260\351\207\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageItem: public Ui_MessageItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEITEM_H
