/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDEMO;
    QAction *actionDEMO_KORTTI_1_PIN_KOODI;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnNum5;
    QPushButton *btnNum8;
    QPushButton *btnNum2;
    QPushButton *btnNum6;
    QPushButton *btnNum7;
    QPushButton *btnNum1;
    QPushButton *btnNum4;
    QPushButton *btnNum1_9;
    QPushButton *btnNum3;
    QPushButton *btnNum0;
    QPushButton *btnNumEnter;
    QPushButton *btnNumDel;
    QStackedWidget *stackedWidget;
    QWidget *pageStartMenu;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *labelKortinTila;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *labelKortinNumero;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_4;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnEnterPin;
    QPushButton *btnCancelMainwindow;
    QWidget *pageValitseTili;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnValitseCredit;
    QPushButton *btnValitseDebit;
    QWidget *pageMainMenu;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QLabel *labelLastLogin;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_12;
    QLabel *labelAccountType;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btnNostaRahaa;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnTilitapahtumat;
    QPushButton *btnKatsoTiedot;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnKirjauduUlos;
    QWidget *pageNostaRahaa;
    QLabel *label_13;
    QPushButton *btnTakaisin;
    QWidget *pageTiliTapahtumat;
    QLabel *label_14;
    QPushButton *btnTakaisin2;
    QWidget *pageKatsoTiedot;
    QLabel *label_15;
    QPushButton *btnTakaisin3;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuStartWindow;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1291, 633);
        actionDEMO = new QAction(MainWindow);
        actionDEMO->setObjectName("actionDEMO");
        actionDEMO_KORTTI_1_PIN_KOODI = new QAction(MainWindow);
        actionDEMO_KORTTI_1_PIN_KOODI->setObjectName("actionDEMO_KORTTI_1_PIN_KOODI");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(880, 120, 351, 401));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnNum5 = new QPushButton(gridLayoutWidget);
        btnNum5->setObjectName("btnNum5");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnNum5->sizePolicy().hasHeightForWidth());
        btnNum5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnNum5, 1, 1, 1, 1);

        btnNum8 = new QPushButton(gridLayoutWidget);
        btnNum8->setObjectName("btnNum8");
        sizePolicy.setHeightForWidth(btnNum8->sizePolicy().hasHeightForWidth());
        btnNum8->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnNum8, 0, 1, 1, 1);

        btnNum2 = new QPushButton(gridLayoutWidget);
        btnNum2->setObjectName("btnNum2");
        sizePolicy.setHeightForWidth(btnNum2->sizePolicy().hasHeightForWidth());
        btnNum2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnNum2, 2, 1, 1, 1);

        btnNum6 = new QPushButton(gridLayoutWidget);
        btnNum6->setObjectName("btnNum6");
        sizePolicy.setHeightForWidth(btnNum6->sizePolicy().hasHeightForWidth());
        btnNum6->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnNum6, 1, 2, 1, 1);

        btnNum7 = new QPushButton(gridLayoutWidget);
        btnNum7->setObjectName("btnNum7");
        sizePolicy.setHeightForWidth(btnNum7->sizePolicy().hasHeightForWidth());
        btnNum7->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnNum7, 0, 0, 1, 1);

        btnNum1 = new QPushButton(gridLayoutWidget);
        btnNum1->setObjectName("btnNum1");
        sizePolicy.setHeightForWidth(btnNum1->sizePolicy().hasHeightForWidth());
        btnNum1->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnNum1, 2, 0, 1, 1);

        btnNum4 = new QPushButton(gridLayoutWidget);
        btnNum4->setObjectName("btnNum4");
        sizePolicy.setHeightForWidth(btnNum4->sizePolicy().hasHeightForWidth());
        btnNum4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnNum4, 1, 0, 1, 1);

        btnNum1_9 = new QPushButton(gridLayoutWidget);
        btnNum1_9->setObjectName("btnNum1_9");
        sizePolicy.setHeightForWidth(btnNum1_9->sizePolicy().hasHeightForWidth());
        btnNum1_9->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnNum1_9, 0, 2, 1, 1);

        btnNum3 = new QPushButton(gridLayoutWidget);
        btnNum3->setObjectName("btnNum3");
        sizePolicy.setHeightForWidth(btnNum3->sizePolicy().hasHeightForWidth());
        btnNum3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnNum3, 2, 2, 1, 1);

        btnNum0 = new QPushButton(gridLayoutWidget);
        btnNum0->setObjectName("btnNum0");
        sizePolicy.setHeightForWidth(btnNum0->sizePolicy().hasHeightForWidth());
        btnNum0->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnNum0, 3, 0, 1, 1);

        btnNumEnter = new QPushButton(gridLayoutWidget);
        btnNumEnter->setObjectName("btnNumEnter");
        sizePolicy.setHeightForWidth(btnNumEnter->sizePolicy().hasHeightForWidth());
        btnNumEnter->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnNumEnter, 3, 1, 1, 1);

        btnNumDel = new QPushButton(gridLayoutWidget);
        btnNumDel->setObjectName("btnNumDel");
        sizePolicy.setHeightForWidth(btnNumDel->sizePolicy().hasHeightForWidth());
        btnNumDel->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btnNumDel, 3, 2, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 0, 751, 581));
        pageStartMenu = new QWidget();
        pageStartMenu->setObjectName("pageStartMenu");
        verticalLayoutWidget = new QWidget(pageStartMenu);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(140, 10, 441, 210));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        labelKortinTila = new QLabel(verticalLayoutWidget);
        labelKortinTila->setObjectName("labelKortinTila");
        QFont font1;
        font1.setPointSize(28);
        labelKortinTila->setFont(font1);
        labelKortinTila->setFrameShadow(QFrame::Plain);

        verticalLayout->addWidget(labelKortinTila, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setPointSize(22);
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);

        labelKortinNumero = new QLabel(verticalLayoutWidget);
        labelKortinNumero->setObjectName("labelKortinNumero");
        labelKortinNumero->setFont(font2);

        horizontalLayout->addWidget(labelKortinNumero);


        verticalLayout->addLayout(horizontalLayout);

        gridLayoutWidget_2 = new QWidget(pageStartMenu);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(110, 190, 511, 221));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 0, 3, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 0, 2, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 0, 1, 1, 1);

        horizontalLayoutWidget_2 = new QWidget(pageStartMenu);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(120, 430, 431, 141));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnEnterPin = new QPushButton(horizontalLayoutWidget_2);
        btnEnterPin->setObjectName("btnEnterPin");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnEnterPin->sizePolicy().hasHeightForWidth());
        btnEnterPin->setSizePolicy(sizePolicy1);
        btnEnterPin->setMinimumSize(QSize(212, 24));
        btnEnterPin->setCheckable(false);

        horizontalLayout_2->addWidget(btnEnterPin);

        btnCancelMainwindow = new QPushButton(horizontalLayoutWidget_2);
        btnCancelMainwindow->setObjectName("btnCancelMainwindow");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnCancelMainwindow->sizePolicy().hasHeightForWidth());
        btnCancelMainwindow->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(btnCancelMainwindow);

        stackedWidget->addWidget(pageStartMenu);
        pageValitseTili = new QWidget();
        pageValitseTili->setObjectName("pageValitseTili");
        verticalLayoutWidget_2 = new QWidget(pageValitseTili);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(180, 190, 331, 251));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName("label_9");
        label_9->setFont(font);

        verticalLayout_3->addWidget(label_9, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        btnValitseCredit = new QPushButton(verticalLayoutWidget_2);
        btnValitseCredit->setObjectName("btnValitseCredit");
        sizePolicy.setHeightForWidth(btnValitseCredit->sizePolicy().hasHeightForWidth());
        btnValitseCredit->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(btnValitseCredit);

        btnValitseDebit = new QPushButton(verticalLayoutWidget_2);
        btnValitseDebit->setObjectName("btnValitseDebit");
        sizePolicy.setHeightForWidth(btnValitseDebit->sizePolicy().hasHeightForWidth());
        btnValitseDebit->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(btnValitseDebit);


        verticalLayout_3->addLayout(horizontalLayout_4);

        stackedWidget->addWidget(pageValitseTili);
        pageMainMenu = new QWidget();
        pageMainMenu->setObjectName("pageMainMenu");
        verticalLayoutWidget_3 = new QWidget(pageMainMenu);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(30, 10, 748, 561));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName("label_10");
        QFont font3;
        font3.setPointSize(36);
        label_10->setFont(font3);

        verticalLayout_5->addWidget(label_10, 0, Qt::AlignHCenter);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName("label_11");
        label_11->setFont(font2);

        horizontalLayout_5->addWidget(label_11);

        labelLastLogin = new QLabel(verticalLayoutWidget_3);
        labelLastLogin->setObjectName("labelLastLogin");
        labelLastLogin->setFont(font2);

        horizontalLayout_5->addWidget(labelLastLogin);


        verticalLayout_5->addLayout(horizontalLayout_5);


        verticalLayout_4->addLayout(verticalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_12 = new QLabel(verticalLayoutWidget_3);
        label_12->setObjectName("label_12");
        QFont font4;
        font4.setPointSize(16);
        label_12->setFont(font4);

        horizontalLayout_6->addWidget(label_12);

        labelAccountType = new QLabel(verticalLayoutWidget_3);
        labelAccountType->setObjectName("labelAccountType");
        labelAccountType->setFont(font4);

        horizontalLayout_6->addWidget(labelAccountType);


        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        btnNostaRahaa = new QPushButton(verticalLayoutWidget_3);
        btnNostaRahaa->setObjectName("btnNostaRahaa");
        sizePolicy.setHeightForWidth(btnNostaRahaa->sizePolicy().hasHeightForWidth());
        btnNostaRahaa->setSizePolicy(sizePolicy);
        QFont font5;
        font5.setPointSize(22);
        font5.setBold(true);
        btnNostaRahaa->setFont(font5);

        verticalLayout_6->addWidget(btnNostaRahaa);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        btnTilitapahtumat = new QPushButton(verticalLayoutWidget_3);
        btnTilitapahtumat->setObjectName("btnTilitapahtumat");
        sizePolicy.setHeightForWidth(btnTilitapahtumat->sizePolicy().hasHeightForWidth());
        btnTilitapahtumat->setSizePolicy(sizePolicy);
        QFont font6;
        font6.setPointSize(20);
        font6.setBold(true);
        btnTilitapahtumat->setFont(font6);

        horizontalLayout_7->addWidget(btnTilitapahtumat);

        btnKatsoTiedot = new QPushButton(verticalLayoutWidget_3);
        btnKatsoTiedot->setObjectName("btnKatsoTiedot");
        sizePolicy.setHeightForWidth(btnKatsoTiedot->sizePolicy().hasHeightForWidth());
        btnKatsoTiedot->setSizePolicy(sizePolicy);
        btnKatsoTiedot->setFont(font6);
        btnKatsoTiedot->setAutoFillBackground(false);

        horizontalLayout_7->addWidget(btnKatsoTiedot);


        verticalLayout_6->addLayout(horizontalLayout_7);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_3);

        btnKirjauduUlos = new QPushButton(verticalLayoutWidget_3);
        btnKirjauduUlos->setObjectName("btnKirjauduUlos");
        sizePolicy.setHeightForWidth(btnKirjauduUlos->sizePolicy().hasHeightForWidth());
        btnKirjauduUlos->setSizePolicy(sizePolicy);
        btnKirjauduUlos->setFont(font5);

        verticalLayout_6->addWidget(btnKirjauduUlos);


        verticalLayout_4->addLayout(verticalLayout_6);

        stackedWidget->addWidget(pageMainMenu);
        pageNostaRahaa = new QWidget();
        pageNostaRahaa->setObjectName("pageNostaRahaa");
        label_13 = new QLabel(pageNostaRahaa);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(200, 10, 271, 91));
        QFont font7;
        font7.setPointSize(26);
        font7.setBold(true);
        label_13->setFont(font7);
        btnTakaisin = new QPushButton(pageNostaRahaa);
        btnTakaisin->setObjectName("btnTakaisin");
        btnTakaisin->setGeometry(QRect(200, 440, 331, 91));
        btnTakaisin->setBaseSize(QSize(0, 5));
        btnTakaisin->setFont(font5);
        stackedWidget->addWidget(pageNostaRahaa);
        pageTiliTapahtumat = new QWidget();
        pageTiliTapahtumat->setObjectName("pageTiliTapahtumat");
        label_14 = new QLabel(pageTiliTapahtumat);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(190, 20, 311, 91));
        label_14->setFont(font7);
        btnTakaisin2 = new QPushButton(pageTiliTapahtumat);
        btnTakaisin2->setObjectName("btnTakaisin2");
        btnTakaisin2->setGeometry(QRect(220, 440, 231, 81));
        stackedWidget->addWidget(pageTiliTapahtumat);
        pageKatsoTiedot = new QWidget();
        pageKatsoTiedot->setObjectName("pageKatsoTiedot");
        label_15 = new QLabel(pageKatsoTiedot);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(150, 30, 441, 91));
        label_15->setFont(font7);
        btnTakaisin3 = new QPushButton(pageKatsoTiedot);
        btnTakaisin3->setObjectName("btnTakaisin3");
        btnTakaisin3->setGeometry(QRect(200, 410, 271, 121));
        stackedWidget->addWidget(pageKatsoTiedot);
        MainWindow->setCentralWidget(centralwidget);
        stackedWidget->raise();
        gridLayoutWidget->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1291, 22));
        menuStartWindow = new QMenu(menubar);
        menuStartWindow->setObjectName("menuStartWindow");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuStartWindow->menuAction());
        menuStartWindow->addAction(actionDEMO);
        menuStartWindow->addAction(actionDEMO_KORTTI_1_PIN_KOODI);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionDEMO->setText(QCoreApplication::translate("MainWindow", "DEMO KORTTI 1", nullptr));
        actionDEMO_KORTTI_1_PIN_KOODI->setText(QCoreApplication::translate("MainWindow", "[PH]DEMO KORTTI 1 PIN KOODI", nullptr));
        btnNum5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btnNum8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        btnNum2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btnNum6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btnNum7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        btnNum1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btnNum4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        btnNum1_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        btnNum3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        btnNum0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnNumEnter->setText(QCoreApplication::translate("MainWindow", "ENTER", nullptr));
        btnNumDel->setText(QCoreApplication::translate("MainWindow", "DEL", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Bankkimaattori", nullptr));
        labelKortinTila->setText(QCoreApplication::translate("MainWindow", "Sy\303\266t\303\244 kortti", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Kortin numero:", nullptr));
        labelKortinNumero->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btnEnterPin->setText(QCoreApplication::translate("MainWindow", "ENTER", nullptr));
        btnCancelMainwindow->setText(QCoreApplication::translate("MainWindow", "CANCEL", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Valitse Tili", nullptr));
        btnValitseCredit->setText(QCoreApplication::translate("MainWindow", "Credit", nullptr));
        btnValitseDebit->setText(QCoreApplication::translate("MainWindow", "Debit", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Tervetuloa N.N.", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Viimeisin sis\303\244\303\244nkirjatuminen:", nullptr));
        labelLastLogin->setText(QCoreApplication::translate("MainWindow", "[PH] P\303\244iv\303\244m\303\244\303\244r\303\244", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Tilin tyyppi:", nullptr));
        labelAccountType->setText(QCoreApplication::translate("MainWindow", "CREDIT/DEBIT", nullptr));
        btnNostaRahaa->setText(QCoreApplication::translate("MainWindow", "NOSTA RAHAA", nullptr));
        btnTilitapahtumat->setText(QCoreApplication::translate("MainWindow", "TILITAPAHTUMAT", nullptr));
        btnKatsoTiedot->setText(QCoreApplication::translate("MainWindow", "KATSO K\303\204YTT\303\204J\303\204TIEDOT", nullptr));
        btnKirjauduUlos->setText(QCoreApplication::translate("MainWindow", "KIRJAUDU ULOS", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "NOSTA RAHAA", nullptr));
        btnTakaisin->setText(QCoreApplication::translate("MainWindow", "TAKAISIN", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "TILI TAPAHTUMAT", nullptr));
        btnTakaisin2->setText(QCoreApplication::translate("MainWindow", "TAKAISIN", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "KATSO K\303\204YTT\303\204J\303\204TIEDOT", nullptr));
        btnTakaisin3->setText(QCoreApplication::translate("MainWindow", "TAKAISIN", nullptr));
        menuStartWindow->setTitle(QCoreApplication::translate("MainWindow", "DEMO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
