/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDEMO;
    QAction *actionDEMO_KORTTI_1_PIN_KOODI;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *pageStartMenu;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *labelKortinTila;
    QPushButton *btn;
    QLineEdit *line;
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
    QTableView *tableTransactions;
    QPushButton *pushButtonTapaht;
    QLabel *labelValittu;
    QWidget *pageKatsoTiedot;
    QPushButton *btnTakaisin3;
    QLabel *labelAccountInfo;
    QLabel *labelTransactionHistory;
    QWidget *gridLayoutWidget_3;
    QGridLayout *transactionGrid;
    QLabel *transactionAmount2;
    QLabel *transactionAmount5;
    QLabel *transactionDate5;
    QLabel *transactionDate4;
    QLabel *transactionAmount1;
    QLabel *transactionAmount4;
    QLabel *transactionDate2;
    QLabel *transactionAmount3;
    QLabel *transactionDate1;
    QLabel *transactionDate3;
    QLabel *transactionDescription1;
    QLabel *transactionDescription2;
    QLabel *transactionDescription3;
    QLabel *transactionDescription4;
    QLabel *transactionDescription5;
    QWidget *gridLayoutWidget_4;
    QGridLayout *cardGrid;
    QLabel *displayCardID;
    QLabel *displayCardOwner;
    QLabel *labelCardOwnerID;
    QLabel *labelCardOwner;
    QLabel *labelCardID;
    QLabel *displayCardOwnerID;
    QWidget *gridLayoutWidget_5;
    QGridLayout *accountGrid;
    QLabel *labelAccountOwner;
    QLabel *displayAccountID;
    QLabel *displayAccountOwner;
    QLabel *labelAccountID;
    QLabel *displayAccountOwnerID;
    QLabel *labelAccountOwnerID;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuStartWindow;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(805, 633);
        actionDEMO = new QAction(MainWindow);
        actionDEMO->setObjectName("actionDEMO");
        actionDEMO_KORTTI_1_PIN_KOODI = new QAction(MainWindow);
        actionDEMO_KORTTI_1_PIN_KOODI->setObjectName("actionDEMO_KORTTI_1_PIN_KOODI");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 751, 581));
        pageStartMenu = new QWidget();
        pageStartMenu->setObjectName("pageStartMenu");
        verticalLayoutWidget = new QWidget(pageStartMenu);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(130, 10, 461, 210));
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

        btn = new QPushButton(pageStartMenu);
        btn->setObjectName("btn");
        btn->setGeometry(QRect(130, 470, 111, 41));
        line = new QLineEdit(pageStartMenu);
        line->setObjectName("line");
        line->setGeometry(QRect(130, 520, 113, 28));
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
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
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
        verticalLayoutWidget_3->setGeometry(QRect(20, 10, 748, 567));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName("label_10");
        QFont font2;
        font2.setPointSize(36);
        label_10->setFont(font2);

        verticalLayout_5->addWidget(label_10, 0, Qt::AlignHCenter);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName("label_11");
        QFont font3;
        font3.setPointSize(22);
        label_11->setFont(font3);

        horizontalLayout_5->addWidget(label_11);

        labelLastLogin = new QLabel(verticalLayoutWidget_3);
        labelLastLogin->setObjectName("labelLastLogin");
        labelLastLogin->setFont(font3);

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
        label_14->setGeometry(QRect(190, 20, 381, 91));
        label_14->setFont(font7);
        btnTakaisin2 = new QPushButton(pageTiliTapahtumat);
        btnTakaisin2->setObjectName("btnTakaisin2");
        btnTakaisin2->setGeometry(QRect(230, 370, 231, 81));
        tableTransactions = new QTableView(pageTiliTapahtumat);
        tableTransactions->setObjectName("tableTransactions");
        tableTransactions->setGeometry(QRect(200, 130, 256, 192));
        tableTransactions->setSelectionMode(QAbstractItemView::SingleSelection);
        pushButtonTapaht = new QPushButton(pageTiliTapahtumat);
        pushButtonTapaht->setObjectName("pushButtonTapaht");
        pushButtonTapaht->setGeometry(QRect(200, 100, 75, 24));
        labelValittu = new QLabel(pageTiliTapahtumat);
        labelValittu->setObjectName("labelValittu");
        labelValittu->setGeometry(QRect(210, 330, 49, 16));
        stackedWidget->addWidget(pageTiliTapahtumat);
        pageKatsoTiedot = new QWidget();
        pageKatsoTiedot->setObjectName("pageKatsoTiedot");
        btnTakaisin3 = new QPushButton(pageKatsoTiedot);
        btnTakaisin3->setObjectName("btnTakaisin3");
        btnTakaisin3->setGeometry(QRect(540, 520, 181, 51));
        labelAccountInfo = new QLabel(pageKatsoTiedot);
        labelAccountInfo->setObjectName("labelAccountInfo");
        labelAccountInfo->setGeometry(QRect(20, 10, 471, 41));
        labelAccountInfo->setFont(font3);
        labelTransactionHistory = new QLabel(pageKatsoTiedot);
        labelTransactionHistory->setObjectName("labelTransactionHistory");
        labelTransactionHistory->setGeometry(QRect(20, 240, 511, 31));
        labelTransactionHistory->setFont(font4);
        gridLayoutWidget_3 = new QWidget(pageKatsoTiedot);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(20, 280, 701, 221));
        transactionGrid = new QGridLayout(gridLayoutWidget_3);
        transactionGrid->setObjectName("transactionGrid");
        transactionGrid->setContentsMargins(0, 0, 0, 0);
        transactionAmount2 = new QLabel(gridLayoutWidget_3);
        transactionAmount2->setObjectName("transactionAmount2");
        QFont font8;
        font8.setPointSize(14);
        transactionAmount2->setFont(font8);

        transactionGrid->addWidget(transactionAmount2, 1, 0, 1, 1);

        transactionAmount5 = new QLabel(gridLayoutWidget_3);
        transactionAmount5->setObjectName("transactionAmount5");
        transactionAmount5->setFont(font8);

        transactionGrid->addWidget(transactionAmount5, 4, 0, 1, 1);

        transactionDate5 = new QLabel(gridLayoutWidget_3);
        transactionDate5->setObjectName("transactionDate5");
        transactionDate5->setFont(font8);
        transactionDate5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        transactionGrid->addWidget(transactionDate5, 4, 1, 1, 1);

        transactionDate4 = new QLabel(gridLayoutWidget_3);
        transactionDate4->setObjectName("transactionDate4");
        transactionDate4->setFont(font8);
        transactionDate4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        transactionGrid->addWidget(transactionDate4, 3, 1, 1, 1);

        transactionAmount1 = new QLabel(gridLayoutWidget_3);
        transactionAmount1->setObjectName("transactionAmount1");
        transactionAmount1->setFont(font8);

        transactionGrid->addWidget(transactionAmount1, 0, 0, 1, 1);

        transactionAmount4 = new QLabel(gridLayoutWidget_3);
        transactionAmount4->setObjectName("transactionAmount4");
        transactionAmount4->setFont(font8);

        transactionGrid->addWidget(transactionAmount4, 3, 0, 1, 1);

        transactionDate2 = new QLabel(gridLayoutWidget_3);
        transactionDate2->setObjectName("transactionDate2");
        transactionDate2->setFont(font8);
        transactionDate2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        transactionGrid->addWidget(transactionDate2, 1, 1, 1, 1);

        transactionAmount3 = new QLabel(gridLayoutWidget_3);
        transactionAmount3->setObjectName("transactionAmount3");
        transactionAmount3->setFont(font8);

        transactionGrid->addWidget(transactionAmount3, 2, 0, 1, 1);

        transactionDate1 = new QLabel(gridLayoutWidget_3);
        transactionDate1->setObjectName("transactionDate1");
        transactionDate1->setFont(font8);
        transactionDate1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        transactionGrid->addWidget(transactionDate1, 0, 1, 1, 1);

        transactionDate3 = new QLabel(gridLayoutWidget_3);
        transactionDate3->setObjectName("transactionDate3");
        transactionDate3->setFont(font8);
        transactionDate3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        transactionGrid->addWidget(transactionDate3, 2, 1, 1, 1);

        transactionDescription1 = new QLabel(gridLayoutWidget_3);
        transactionDescription1->setObjectName("transactionDescription1");
        transactionDescription1->setFont(font8);
        transactionDescription1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        transactionGrid->addWidget(transactionDescription1, 0, 2, 1, 1);

        transactionDescription2 = new QLabel(gridLayoutWidget_3);
        transactionDescription2->setObjectName("transactionDescription2");
        transactionDescription2->setFont(font8);
        transactionDescription2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        transactionGrid->addWidget(transactionDescription2, 1, 2, 1, 1);

        transactionDescription3 = new QLabel(gridLayoutWidget_3);
        transactionDescription3->setObjectName("transactionDescription3");
        transactionDescription3->setFont(font8);
        transactionDescription3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        transactionGrid->addWidget(transactionDescription3, 2, 2, 1, 1);

        transactionDescription4 = new QLabel(gridLayoutWidget_3);
        transactionDescription4->setObjectName("transactionDescription4");
        transactionDescription4->setFont(font8);
        transactionDescription4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        transactionGrid->addWidget(transactionDescription4, 3, 2, 1, 1);

        transactionDescription5 = new QLabel(gridLayoutWidget_3);
        transactionDescription5->setObjectName("transactionDescription5");
        transactionDescription5->setFont(font8);
        transactionDescription5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        transactionGrid->addWidget(transactionDescription5, 4, 2, 1, 1);

        gridLayoutWidget_4 = new QWidget(pageKatsoTiedot);
        gridLayoutWidget_4->setObjectName("gridLayoutWidget_4");
        gridLayoutWidget_4->setGeometry(QRect(400, 60, 351, 161));
        cardGrid = new QGridLayout(gridLayoutWidget_4);
        cardGrid->setObjectName("cardGrid");
        cardGrid->setContentsMargins(0, 0, 0, 0);
        displayCardID = new QLabel(gridLayoutWidget_4);
        displayCardID->setObjectName("displayCardID");
        QFont font9;
        font9.setPointSize(10);
        displayCardID->setFont(font9);

        cardGrid->addWidget(displayCardID, 3, 1, 1, 1);

        displayCardOwner = new QLabel(gridLayoutWidget_4);
        displayCardOwner->setObjectName("displayCardOwner");
        displayCardOwner->setFont(font9);

        cardGrid->addWidget(displayCardOwner, 0, 1, 1, 1);

        labelCardOwnerID = new QLabel(gridLayoutWidget_4);
        labelCardOwnerID->setObjectName("labelCardOwnerID");
        labelCardOwnerID->setFont(font9);

        cardGrid->addWidget(labelCardOwnerID, 2, 0, 1, 1);

        labelCardOwner = new QLabel(gridLayoutWidget_4);
        labelCardOwner->setObjectName("labelCardOwner");
        labelCardOwner->setFont(font9);

        cardGrid->addWidget(labelCardOwner, 0, 0, 1, 1);

        labelCardID = new QLabel(gridLayoutWidget_4);
        labelCardID->setObjectName("labelCardID");
        labelCardID->setFont(font9);

        cardGrid->addWidget(labelCardID, 3, 0, 1, 1);

        displayCardOwnerID = new QLabel(gridLayoutWidget_4);
        displayCardOwnerID->setObjectName("displayCardOwnerID");
        displayCardOwnerID->setFont(font9);

        cardGrid->addWidget(displayCardOwnerID, 2, 1, 1, 1);

        gridLayoutWidget_5 = new QWidget(pageKatsoTiedot);
        gridLayoutWidget_5->setObjectName("gridLayoutWidget_5");
        gridLayoutWidget_5->setGeometry(QRect(21, 59, 371, 161));
        accountGrid = new QGridLayout(gridLayoutWidget_5);
        accountGrid->setObjectName("accountGrid");
        accountGrid->setContentsMargins(0, 0, 0, 0);
        labelAccountOwner = new QLabel(gridLayoutWidget_5);
        labelAccountOwner->setObjectName("labelAccountOwner");
        labelAccountOwner->setFont(font9);

        accountGrid->addWidget(labelAccountOwner, 0, 0, 1, 1);

        displayAccountID = new QLabel(gridLayoutWidget_5);
        displayAccountID->setObjectName("displayAccountID");
        displayAccountID->setFont(font9);

        accountGrid->addWidget(displayAccountID, 3, 1, 1, 1);

        displayAccountOwner = new QLabel(gridLayoutWidget_5);
        displayAccountOwner->setObjectName("displayAccountOwner");
        displayAccountOwner->setFont(font9);

        accountGrid->addWidget(displayAccountOwner, 0, 1, 1, 1);

        labelAccountID = new QLabel(gridLayoutWidget_5);
        labelAccountID->setObjectName("labelAccountID");
        labelAccountID->setFont(font9);

        accountGrid->addWidget(labelAccountID, 3, 0, 1, 1);

        displayAccountOwnerID = new QLabel(gridLayoutWidget_5);
        displayAccountOwnerID->setObjectName("displayAccountOwnerID");
        displayAccountOwnerID->setFont(font9);

        accountGrid->addWidget(displayAccountOwnerID, 1, 1, 1, 1);

        labelAccountOwnerID = new QLabel(gridLayoutWidget_5);
        labelAccountOwnerID->setObjectName("labelAccountOwnerID");
        labelAccountOwnerID->setFont(font9);

        accountGrid->addWidget(labelAccountOwnerID, 1, 0, 1, 1);

        stackedWidget->addWidget(pageKatsoTiedot);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 805, 22));
        menuStartWindow = new QMenu(menubar);
        menuStartWindow->setObjectName("menuStartWindow");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuStartWindow->menuAction());
        menuStartWindow->addAction(actionDEMO);
        menuStartWindow->addAction(actionDEMO_KORTTI_1_PIN_KOODI);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionDEMO->setText(QCoreApplication::translate("MainWindow", "DEMO KORTTI 1", nullptr));
        actionDEMO_KORTTI_1_PIN_KOODI->setText(QCoreApplication::translate("MainWindow", "[PH]DEMO KORTTI 1 PIN KOODI", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Bankkimaattori", nullptr));
        labelKortinTila->setText(QCoreApplication::translate("MainWindow", "Sy\303\266t\303\244 kortti", nullptr));
        btn->setText(QCoreApplication::translate("MainWindow", "DLL DEMO", nullptr));
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
        btnKatsoTiedot->setText(QCoreApplication::translate("MainWindow", "K\303\204YTT\303\204J\303\204TIEDOT", nullptr));
        btnKirjauduUlos->setText(QCoreApplication::translate("MainWindow", "KIRJAUDU ULOS", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "NOSTA RAHAA", nullptr));
        btnTakaisin->setText(QCoreApplication::translate("MainWindow", "TAKAISIN", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "TILI TAPAHTUMAT", nullptr));
        btnTakaisin2->setText(QCoreApplication::translate("MainWindow", "TAKAISIN", nullptr));
        pushButtonTapaht->setText(QCoreApplication::translate("MainWindow", "N\303\244yt\303\244", nullptr));
        labelValittu->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btnTakaisin3->setText(QCoreApplication::translate("MainWindow", "TAKAISIN", nullptr));
        labelAccountInfo->setText(QCoreApplication::translate("MainWindow", "CARD AND ACCOUNT INFORMATION", nullptr));
        labelTransactionHistory->setText(QCoreApplication::translate("MainWindow", "Transaction history:", nullptr));
        transactionAmount2->setText(QCoreApplication::translate("MainWindow", "amount", nullptr));
        transactionAmount5->setText(QCoreApplication::translate("MainWindow", "amount", nullptr));
        transactionDate5->setText(QCoreApplication::translate("MainWindow", "date", nullptr));
        transactionDate4->setText(QCoreApplication::translate("MainWindow", "date", nullptr));
        transactionAmount1->setText(QCoreApplication::translate("MainWindow", "amount", nullptr));
        transactionAmount4->setText(QCoreApplication::translate("MainWindow", "amount", nullptr));
        transactionDate2->setText(QCoreApplication::translate("MainWindow", "date", nullptr));
        transactionAmount3->setText(QCoreApplication::translate("MainWindow", "amount", nullptr));
        transactionDate1->setText(QCoreApplication::translate("MainWindow", "date", nullptr));
        transactionDate3->setText(QCoreApplication::translate("MainWindow", "date", nullptr));
        transactionDescription1->setText(QCoreApplication::translate("MainWindow", "description", nullptr));
        transactionDescription2->setText(QCoreApplication::translate("MainWindow", "description", nullptr));
        transactionDescription3->setText(QCoreApplication::translate("MainWindow", "description", nullptr));
        transactionDescription4->setText(QCoreApplication::translate("MainWindow", "description", nullptr));
        transactionDescription5->setText(QCoreApplication::translate("MainWindow", "description", nullptr));
        displayCardID->setText(QCoreApplication::translate("MainWindow", "number", nullptr));
        displayCardOwner->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        labelCardOwnerID->setText(QCoreApplication::translate("MainWindow", "Card owner ID:", nullptr));
        labelCardOwner->setText(QCoreApplication::translate("MainWindow", "Card owner:", nullptr));
        labelCardID->setText(QCoreApplication::translate("MainWindow", "Card ID:", nullptr));
        displayCardOwnerID->setText(QCoreApplication::translate("MainWindow", "number", nullptr));
        labelAccountOwner->setText(QCoreApplication::translate("MainWindow", "Account owner:", nullptr));
        displayAccountID->setText(QCoreApplication::translate("MainWindow", "number", nullptr));
        displayAccountOwner->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        labelAccountID->setText(QCoreApplication::translate("MainWindow", "Account ID:", nullptr));
        displayAccountOwnerID->setText(QCoreApplication::translate("MainWindow", "number", nullptr));
        labelAccountOwnerID->setText(QCoreApplication::translate("MainWindow", "Account owner ID:", nullptr));
        menuStartWindow->setTitle(QCoreApplication::translate("MainWindow", "DEMO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
