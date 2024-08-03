/********************************************************************************
** Form generated from reading UI file 'addfriendwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIENDWIDGET_H
#define UI_ADDFRIENDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFriendWidget
{
public:
    QLineEdit *FindEdit;
    QPushButton *FindButton;

    void setupUi(QWidget *AddFriendWidget)
    {
        if (AddFriendWidget->objectName().isEmpty())
            AddFriendWidget->setObjectName("AddFriendWidget");
        AddFriendWidget->resize(700, 500);
        AddFriendWidget->setMinimumSize(QSize(700, 500));
        AddFriendWidget->setMaximumSize(QSize(700, 500));
        FindEdit = new QLineEdit(AddFriendWidget);
        FindEdit->setObjectName("FindEdit");
        FindEdit->setGeometry(QRect(60, 40, 300, 30));
        FindButton = new QPushButton(AddFriendWidget);
        FindButton->setObjectName("FindButton");
        FindButton->setGeometry(QRect(420, 100, 80, 25));

        retranslateUi(AddFriendWidget);

        QMetaObject::connectSlotsByName(AddFriendWidget);
    } // setupUi

    void retranslateUi(QWidget *AddFriendWidget)
    {
        AddFriendWidget->setWindowTitle(QCoreApplication::translate("AddFriendWidget", "Form", nullptr));
        FindButton->setText(QCoreApplication::translate("AddFriendWidget", "\346\237\245\346\211\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFriendWidget: public Ui_AddFriendWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIENDWIDGET_H
