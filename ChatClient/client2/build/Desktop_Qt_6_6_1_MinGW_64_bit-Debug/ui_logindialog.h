/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QLabel *IdLabel;
    QLineEdit *IdLineEdit;
    QSplitter *splitter_2;
    QLabel *PasswordLabel;
    QLineEdit *PasswordLineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Login;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Regit;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QLineEdit *serverIplineEdit;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(292, 133);
        verticalLayout = new QVBoxLayout(LoginDialog);
        verticalLayout->setObjectName("verticalLayout");
        splitter = new QSplitter(LoginDialog);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        IdLabel = new QLabel(splitter);
        IdLabel->setObjectName("IdLabel");
        splitter->addWidget(IdLabel);
        IdLineEdit = new QLineEdit(splitter);
        IdLineEdit->setObjectName("IdLineEdit");
        splitter->addWidget(IdLineEdit);

        verticalLayout->addWidget(splitter);

        splitter_2 = new QSplitter(LoginDialog);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Horizontal);
        PasswordLabel = new QLabel(splitter_2);
        PasswordLabel->setObjectName("PasswordLabel");
        splitter_2->addWidget(PasswordLabel);
        PasswordLineEdit = new QLineEdit(splitter_2);
        PasswordLineEdit->setObjectName("PasswordLineEdit");
        splitter_2->addWidget(PasswordLineEdit);

        verticalLayout->addWidget(splitter_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Login = new QPushButton(LoginDialog);
        Login->setObjectName("Login");

        horizontalLayout->addWidget(Login);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Regit = new QPushButton(LoginDialog);
        Regit->setObjectName("Regit");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Regit->sizePolicy().hasHeightForWidth());
        Regit->setSizePolicy(sizePolicy);
        Regit->setMinimumSize(QSize(41, 16));
        Regit->setMaximumSize(QSize(41, 16));

        horizontalLayout_2->addWidget(Regit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label = new QLabel(LoginDialog);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        serverIplineEdit = new QLineEdit(LoginDialog);
        serverIplineEdit->setObjectName("serverIplineEdit");

        horizontalLayout_2->addWidget(serverIplineEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        IdLabel->setText(QCoreApplication::translate("LoginDialog", "QQ:", nullptr));
        PasswordLabel->setText(QCoreApplication::translate("LoginDialog", "Password:", nullptr));
        Login->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        Regit->setText(QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
        label->setText(QCoreApplication::translate("LoginDialog", "serverIp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
