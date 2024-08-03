/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter_2;
    QLabel *headshot;
    QSplitter *splitter;
    QLabel *id;
    QLabel *name;
    QSpacerItem *horizontalSpacer;
    QPushButton *addFriend;
    QTabWidget *waitanswerAddWidget;
    QWidget *MessageTab;
    QGridLayout *gridLayout;
    QListWidget *MessageList;
    QWidget *FriendTab;
    QGridLayout *gridLayout_2;
    QListWidget *FriendList;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QListWidget *waitWidget;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(381, 615);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Horizontal);
        headshot = new QLabel(splitter_2);
        headshot->setObjectName("headshot");
        headshot->setMinimumSize(QSize(60, 60));
        headshot->setMaximumSize(QSize(60, 60));
        headshot->setAlignment(Qt::AlignCenter);
        splitter_2->addWidget(headshot);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Vertical);
        id = new QLabel(splitter);
        id->setObjectName("id");
        id->setMinimumSize(QSize(120, 0));
        id->setBaseSize(QSize(60, 25));
        id->setAlignment(Qt::AlignCenter);
        splitter->addWidget(id);
        name = new QLabel(splitter);
        name->setObjectName("name");
        name->setMinimumSize(QSize(60, 0));
        name->setAlignment(Qt::AlignCenter);
        splitter->addWidget(name);
        splitter_2->addWidget(splitter);

        horizontalLayout->addWidget(splitter_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addFriend = new QPushButton(centralwidget);
        addFriend->setObjectName("addFriend");

        horizontalLayout->addWidget(addFriend);


        verticalLayout->addLayout(horizontalLayout);

        waitanswerAddWidget = new QTabWidget(centralwidget);
        waitanswerAddWidget->setObjectName("waitanswerAddWidget");
        waitanswerAddWidget->setMinimumSize(QSize(291, 0));
        MessageTab = new QWidget();
        MessageTab->setObjectName("MessageTab");
        gridLayout = new QGridLayout(MessageTab);
        gridLayout->setObjectName("gridLayout");
        MessageList = new QListWidget(MessageTab);
        MessageList->setObjectName("MessageList");

        gridLayout->addWidget(MessageList, 0, 0, 1, 1);

        waitanswerAddWidget->addTab(MessageTab, QString());
        FriendTab = new QWidget();
        FriendTab->setObjectName("FriendTab");
        gridLayout_2 = new QGridLayout(FriendTab);
        gridLayout_2->setObjectName("gridLayout_2");
        FriendList = new QListWidget(FriendTab);
        FriendList->setObjectName("FriendList");

        gridLayout_2->addWidget(FriendList, 0, 0, 1, 1);

        waitanswerAddWidget->addTab(FriendTab, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName("gridLayout_3");
        waitWidget = new QListWidget(tab);
        waitWidget->setObjectName("waitWidget");

        gridLayout_3->addWidget(waitWidget, 0, 0, 1, 1);

        waitanswerAddWidget->addTab(tab, QString());

        verticalLayout->addWidget(waitanswerAddWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 381, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        waitanswerAddWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        headshot->setText(QCoreApplication::translate("MainWindow", "\345\244\264\345\203\217", nullptr));
        id->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        name->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        addFriend->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        waitanswerAddWidget->setTabText(waitanswerAddWidget->indexOf(MessageTab), QCoreApplication::translate("MainWindow", "\344\277\241\346\201\257", nullptr));
        waitanswerAddWidget->setTabText(waitanswerAddWidget->indexOf(FriendTab), QCoreApplication::translate("MainWindow", "\350\201\224\347\263\273\344\272\272", nullptr));
        waitanswerAddWidget->setTabText(waitanswerAddWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\345\276\205\345\233\236\345\244\215\347\232\204\345\245\275\345\217\213\347\224\263\350\257\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
