/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidget
{
public:
    QLabel *friendid;
    QListWidget *listWidget;
    QPushButton *pixmap;
    QPushButton *file;
    QTextEdit *InputMessage;
    QPushButton *send;

    void setupUi(QWidget *ChatWidget)
    {
        if (ChatWidget->objectName().isEmpty())
            ChatWidget->setObjectName("ChatWidget");
        ChatWidget->resize(800, 660);
        ChatWidget->setMinimumSize(QSize(800, 660));
        ChatWidget->setMaximumSize(QSize(800, 660));
        friendid = new QLabel(ChatWidget);
        friendid->setObjectName("friendid");
        friendid->setGeometry(QRect(20, 10, 750, 20));
        friendid->setMinimumSize(QSize(750, 20));
        friendid->setMaximumSize(QSize(750, 20));
        friendid->setAlignment(Qt::AlignCenter);
        listWidget = new QListWidget(ChatWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(30, 30, 750, 450));
        listWidget->setMinimumSize(QSize(750, 450));
        listWidget->setMaximumSize(QSize(750, 450));
        pixmap = new QPushButton(ChatWidget);
        pixmap->setObjectName("pixmap");
        pixmap->setGeometry(QRect(100, 570, 70, 30));
        pixmap->setMinimumSize(QSize(70, 30));
        pixmap->setMaximumSize(QSize(70, 30));
        file = new QPushButton(ChatWidget);
        file->setObjectName("file");
        file->setGeometry(QRect(90, 510, 70, 30));
        file->setMinimumSize(QSize(70, 30));
        file->setMaximumSize(QSize(70, 30));
        InputMessage = new QTextEdit(ChatWidget);
        InputMessage->setObjectName("InputMessage");
        InputMessage->setGeometry(QRect(180, 500, 450, 150));
        InputMessage->setMinimumSize(QSize(450, 150));
        InputMessage->setMaximumSize(QSize(450, 150));
        send = new QPushButton(ChatWidget);
        send->setObjectName("send");
        send->setGeometry(QRect(650, 570, 70, 30));
        send->setMinimumSize(QSize(70, 30));
        send->setMaximumSize(QSize(70, 30));

        retranslateUi(ChatWidget);

        QMetaObject::connectSlotsByName(ChatWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatWidget)
    {
        ChatWidget->setWindowTitle(QCoreApplication::translate("ChatWidget", "Form", nullptr));
        friendid->setText(QCoreApplication::translate("ChatWidget", "friendid:", nullptr));
        pixmap->setText(QCoreApplication::translate("ChatWidget", "\345\233\276\347\211\207", nullptr));
        file->setText(QCoreApplication::translate("ChatWidget", "\346\226\207\344\273\266", nullptr));
        send->setText(QCoreApplication::translate("ChatWidget", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWidget: public Ui_ChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
