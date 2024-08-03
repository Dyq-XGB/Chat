/********************************************************************************
** Form generated from reading UI file 'regitdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGITDIALOG_H
#define UI_REGITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegitDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *headshot;
    QSpacerItem *horizontalSpacer_6;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_3;
    QLabel *label_4;
    QLineEdit *nickname;
    QSplitter *splitter_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QSplitter *splitter;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *RegitDialog)
    {
        if (RegitDialog->objectName().isEmpty())
            RegitDialog->setObjectName("RegitDialog");
        RegitDialog->resize(277, 217);
        verticalLayout_3 = new QVBoxLayout(RegitDialog);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        headshot = new QLabel(RegitDialog);
        headshot->setObjectName("headshot");
        headshot->setMinimumSize(QSize(60, 60));
        headshot->setMaximumSize(QSize(60, 60));
        headshot->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(headshot);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_3);

        stackedWidget = new QStackedWidget(RegitDialog);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName("verticalLayout");
        splitter_3 = new QSplitter(page);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(splitter_3);
        label_4->setObjectName("label_4");
        splitter_3->addWidget(label_4);
        nickname = new QLineEdit(splitter_3);
        nickname->setObjectName("nickname");
        splitter_3->addWidget(nickname);

        verticalLayout->addWidget(splitter_3);

        splitter_2 = new QSplitter(page);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter_2);
        label->setObjectName("label");
        splitter_2->addWidget(label);
        lineEdit = new QLineEdit(splitter_2);
        lineEdit->setObjectName("lineEdit");
        splitter_2->addWidget(lineEdit);

        verticalLayout->addWidget(splitter_2);

        splitter = new QSplitter(page);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter);
        label_2->setObjectName("label_2");
        splitter->addWidget(label_2);
        lineEdit_2 = new QLineEdit(splitter);
        lineEdit_2->setObjectName("lineEdit_2");
        splitter->addWidget(lineEdit_2);

        verticalLayout->addWidget(splitter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(page_2);

        verticalLayout_3->addWidget(stackedWidget);


        retranslateUi(RegitDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RegitDialog);
    } // setupUi

    void retranslateUi(QDialog *RegitDialog)
    {
        RegitDialog->setWindowTitle(QCoreApplication::translate("RegitDialog", "Dialog", nullptr));
        headshot->setText(QCoreApplication::translate("RegitDialog", "\345\244\264\345\203\217", nullptr));
        label_4->setText(QCoreApplication::translate("RegitDialog", "\346\230\265\347\247\260\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("RegitDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("RegitDialog", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("RegitDialog", "\347\241\256\350\256\244", nullptr));
        label_3->setText(QCoreApplication::translate("RegitDialog", "\350\264\246\345\217\267\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("RegitDialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegitDialog: public Ui_RegitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGITDIALOG_H
