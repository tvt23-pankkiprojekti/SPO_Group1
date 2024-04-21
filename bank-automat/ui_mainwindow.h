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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *pageStartMenu;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *labelKortinTila;
    QPushButton *btn;
    QLineEdit *lineEdit;
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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QWidget *pageTiliTapahtumat;
    QLabel *label_14;
    QPushButton *btnTakaisin2;
    QTableView *tableEvents;
    QPushButton *pushButtonTapaht;
    QWidget *pageKatsoTiedot;
    QPushButton *btnTakaisin3;
    QLabel *labelAccountInfo;
    QLabel *labelTransactionHistory;
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
    QTableWidget *transactionTable;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(805, 633);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(50, 0, 781, 581));
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
        lineEdit = new QLineEdit(pageStartMenu);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(130, 520, 113, 28));
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
        label_13->setGeometry(QRect(200, 10, 321, 91));
        QFont font7;
        font7.setPointSize(26);
        font7.setBold(true);
        label_13->setFont(font7);
        btnTakaisin = new QPushButton(pageNostaRahaa);
        btnTakaisin->setObjectName("btnTakaisin");
        btnTakaisin->setGeometry(QRect(510, 470, 261, 101));
        btnTakaisin->setBaseSize(QSize(0, 5));
        btnTakaisin->setFont(font5);
        gridLayoutWidget = new QWidget(pageNostaRahaa);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 130, 701, 301));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 1, 1, 1, Qt::AlignHCenter);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName("pushButton_6");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_6, 0, 2, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName("pushButton_5");
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_5, 3, 2, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName("pushButton_7");
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_7, 2, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 3, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);
        pushButton_2->setMaximumSize(QSize(500, 16777215));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 3, 1, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);
        pushButton_3->setMaximumSize(QSize(500, 16777215));

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName("pushButton");
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMaximumSize(QSize(500, 16777215));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName("pushButton_4");
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_4, 1, 2, 1, 1);

        stackedWidget->addWidget(pageNostaRahaa);
        pageTiliTapahtumat = new QWidget();
        pageTiliTapahtumat->setObjectName("pageTiliTapahtumat");
        label_14 = new QLabel(pageTiliTapahtumat);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(190, 20, 381, 91));
        label_14->setFont(font7);
        btnTakaisin2 = new QPushButton(pageTiliTapahtumat);
        btnTakaisin2->setObjectName("btnTakaisin2");
        btnTakaisin2->setGeometry(QRect(200, 510, 231, 81));
        tableEvents = new QTableView(pageTiliTapahtumat);
        tableEvents->setObjectName("tableEvents");
        tableEvents->setGeometry(QRect(160, 130, 351, 341));
        tableEvents->setSelectionMode(QAbstractItemView::SingleSelection);
        pushButtonTapaht = new QPushButton(pageTiliTapahtumat);
        pushButtonTapaht->setObjectName("pushButtonTapaht");
        pushButtonTapaht->setGeometry(QRect(440, 480, 91, 24));
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
        gridLayoutWidget_4 = new QWidget(pageKatsoTiedot);
        gridLayoutWidget_4->setObjectName("gridLayoutWidget_4");
        gridLayoutWidget_4->setGeometry(QRect(400, 60, 351, 161));
        cardGrid = new QGridLayout(gridLayoutWidget_4);
        cardGrid->setObjectName("cardGrid");
        cardGrid->setContentsMargins(0, 0, 0, 0);
        displayCardID = new QLabel(gridLayoutWidget_4);
        displayCardID->setObjectName("displayCardID");
        QFont font8;
        font8.setPointSize(10);
        displayCardID->setFont(font8);

        cardGrid->addWidget(displayCardID, 3, 1, 1, 1);

        displayCardOwner = new QLabel(gridLayoutWidget_4);
        displayCardOwner->setObjectName("displayCardOwner");
        displayCardOwner->setFont(font8);

        cardGrid->addWidget(displayCardOwner, 0, 1, 1, 1);

        labelCardOwnerID = new QLabel(gridLayoutWidget_4);
        labelCardOwnerID->setObjectName("labelCardOwnerID");
        labelCardOwnerID->setFont(font8);

        cardGrid->addWidget(labelCardOwnerID, 2, 0, 1, 1);

        labelCardOwner = new QLabel(gridLayoutWidget_4);
        labelCardOwner->setObjectName("labelCardOwner");
        labelCardOwner->setFont(font8);

        cardGrid->addWidget(labelCardOwner, 0, 0, 1, 1);

        labelCardID = new QLabel(gridLayoutWidget_4);
        labelCardID->setObjectName("labelCardID");
        labelCardID->setFont(font8);

        cardGrid->addWidget(labelCardID, 3, 0, 1, 1);

        displayCardOwnerID = new QLabel(gridLayoutWidget_4);
        displayCardOwnerID->setObjectName("displayCardOwnerID");
        displayCardOwnerID->setFont(font8);

        cardGrid->addWidget(displayCardOwnerID, 2, 1, 1, 1);

        gridLayoutWidget_5 = new QWidget(pageKatsoTiedot);
        gridLayoutWidget_5->setObjectName("gridLayoutWidget_5");
        gridLayoutWidget_5->setGeometry(QRect(21, 59, 371, 161));
        accountGrid = new QGridLayout(gridLayoutWidget_5);
        accountGrid->setObjectName("accountGrid");
        accountGrid->setContentsMargins(0, 0, 0, 0);
        labelAccountOwner = new QLabel(gridLayoutWidget_5);
        labelAccountOwner->setObjectName("labelAccountOwner");
        labelAccountOwner->setFont(font8);

        accountGrid->addWidget(labelAccountOwner, 0, 0, 1, 1);

        displayAccountID = new QLabel(gridLayoutWidget_5);
        displayAccountID->setObjectName("displayAccountID");
        displayAccountID->setFont(font8);

        accountGrid->addWidget(displayAccountID, 3, 1, 1, 1);

        displayAccountOwner = new QLabel(gridLayoutWidget_5);
        displayAccountOwner->setObjectName("displayAccountOwner");
        displayAccountOwner->setFont(font8);

        accountGrid->addWidget(displayAccountOwner, 0, 1, 1, 1);

        labelAccountID = new QLabel(gridLayoutWidget_5);
        labelAccountID->setObjectName("labelAccountID");
        labelAccountID->setFont(font8);

        accountGrid->addWidget(labelAccountID, 3, 0, 1, 1);

        displayAccountOwnerID = new QLabel(gridLayoutWidget_5);
        displayAccountOwnerID->setObjectName("displayAccountOwnerID");
        displayAccountOwnerID->setFont(font8);

        accountGrid->addWidget(displayAccountOwnerID, 1, 1, 1, 1);

        labelAccountOwnerID = new QLabel(gridLayoutWidget_5);
        labelAccountOwnerID->setObjectName("labelAccountOwnerID");
        labelAccountOwnerID->setFont(font8);

        accountGrid->addWidget(labelAccountOwnerID, 1, 0, 1, 1);

        transactionTable = new QTableWidget(pageKatsoTiedot);
        if (transactionTable->columnCount() < 3)
            transactionTable->setColumnCount(3);
        if (transactionTable->rowCount() < 5)
            transactionTable->setRowCount(5);
        transactionTable->setObjectName("transactionTable");
        transactionTable->setGeometry(QRect(20, 270, 741, 201));
        QFont font9;
        font9.setPointSize(12);
        transactionTable->setFont(font9);
        transactionTable->setAutoFillBackground(true);
        transactionTable->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);"));
        transactionTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        transactionTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        transactionTable->setRowCount(5);
        transactionTable->setColumnCount(3);
        transactionTable->horizontalHeader()->setVisible(false);
        transactionTable->horizontalHeader()->setDefaultSectionSize(230);
        transactionTable->horizontalHeader()->setStretchLastSection(true);
        transactionTable->verticalHeader()->setVisible(false);
        transactionTable->verticalHeader()->setDefaultSectionSize(40);
        transactionTable->verticalHeader()->setStretchLastSection(true);
        stackedWidget->addWidget(pageKatsoTiedot);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
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
        label_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Tyhjenn\303\244", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Nosta", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Tyhjenn\303\244", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Tyhjenn\303\244", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "TILI TAPAHTUMAT", nullptr));
        btnTakaisin2->setText(QCoreApplication::translate("MainWindow", "TAKAISIN", nullptr));
        pushButtonTapaht->setText(QCoreApplication::translate("MainWindow", "seuraava sivu", nullptr));
        btnTakaisin3->setText(QCoreApplication::translate("MainWindow", "TAKAISIN", nullptr));
        labelAccountInfo->setText(QCoreApplication::translate("MainWindow", "CARD AND ACCOUNT INFORMATION", nullptr));
        labelTransactionHistory->setText(QCoreApplication::translate("MainWindow", "Transaction history:", nullptr));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
