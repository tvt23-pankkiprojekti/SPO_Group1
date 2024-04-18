#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    cardNo = "060006F233";

    ui->setupUi(this);
    ptr_dll = new Dialog(this);

    connect(ptr_dll,SIGNAL(pincodeReady()),this,SLOT(onBtnEnterPinClicked()));
    connect(ui->btnValitseCredit, SIGNAL(clicked()), this, SLOT(onBtnValitseCreditClicked()));
    connect(ui->btnValitseDebit, SIGNAL(clicked()), this, SLOT(onBtnValitseDebitClicked()));
    connect(ui->btnKirjauduUlos, SIGNAL(clicked()), this, SLOT(onBtnKirjauduUlosClicked()));
    connect(ui->btnNostaRahaa, SIGNAL(clicked()), this, SLOT(onBtnNostaRahaaClicked()));
    connect(ui->btnTilitapahtumat, SIGNAL(clicked()), this, SLOT(onBtnTilitapahtumatClicked()));
    connect(ui->btnTakaisin, SIGNAL(clicked()), this, SLOT(onBtnTakaisinClicked()));
    connect(ui->btnTakaisin2, SIGNAL(clicked()), this, SLOT(onBtnTakaisin2Clicked()));
    connect(ui->btnTakaisin3, SIGNAL(clicked()), this, SLOT(onBtnTakaisin3Clicked()));
    connect(ui->btnKatsoTiedot, SIGNAL(clicked()), this, SLOT(onBtnKatsoTiedotClicked()));

    connect(ui->btn,SIGNAL(clicked(bool)),
            this,SLOT(handleClick()));
    ui->stackedWidget->setCurrentIndex(0);
    accountInfo = new ProfileWindow;
    accountInfo->attachWindow(ui->stackedWidget);
}





void MainWindow::profileDataSlot(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QMessageBox msgBox;

    if (data.length() == 0 || data == "-4078") {
        qDebug() << "Tietoliikenneyhteysvika";
        msgBox.setText("Tietoliikenneyhteysvika");
        msgBox.exec();
        reply->deleteLater();
        transferManager->deleteLater();
        return;
    }

    if (data == "false") {
        qDebug() << "Virhe tietojen hankinnassa";
        msgBox.setText("Tietoa ei saatu");
        msgBox.exec();
        reply->deleteLater();
        transferManager->deleteLater();
        return;
    }

    ui->stackedWidget->setCurrentIndex(5);
    accountInfo->updateUserData(data);

    reply->deleteLater();
    transferManager->deleteLater();
}

void MainWindow::attachedAccountCheckSlot(QNetworkReply *reply)
{
    qDebug() << "attachedAccountCheckSlot()";

    QByteArray data=reply->readAll();
    QMessageBox msgBox;

    if (data=="-4078" || data.length()==0) {
        msgBox.setText("Network error");
        msgBox.exec();
    }
    else {
        if(data == "false"){
            msgBox.setText("Data acquisition error");
            msgBox.exec();
        }

        QJsonDocument dataUnpacked = QJsonDocument::fromJson(data);
        qDebug() << dataUnpacked;
        QJsonArray array = dataUnpacked.array();
        if (array.size() < 1) {
            msgBox.setText("No accounts attached to this card");
            msgBox.exec();
        }
        else if (array.size() < 2) {
            ui->stackedWidget->setCurrentIndex(1);
        }
        else {
            ui->stackedWidget->setCurrentIndex(2);
        }
    }

    accountCheckReply->deleteLater();
    accountCheckManager->deleteLater();
}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    data = reply->readAll();
    qDebug()<<data;
    QMessageBox msgBox;
    qDebug()<<data;
    if(data=="-4078" || data.length()==0){
        msgBox.setText("Virhe tietoyhteydessä");
        msgBox.exec();
    }
    else{
        if(data!="false"){
            msgBox.setText("Kirjautunut");
            //kirjautuminen onnistui
            qDebug() << "loginSLot(), data wasn't false";
            checkAttachedAccounts();
        }
        else{
            msgBox.setText("Väärä tunnus");
            msgBox.exec();
            //ui->textUsername->clear();
            ui->lineEdit->clear();
        }
    }
    reply->deleteLater();
    loginManager->deleteLater();
}

void MainWindow::onBtnEnterPinClicked()
{
    qDebug()<<"enter clicked";
    //ui->stackedWidget->setCurrentIndex(1);
    QString pin=ptr_dll->getPincode();
    QJsonObject jsonObj;
    jsonObj.insert("card", cardNo);
    jsonObj.insert("pincode", pin);

    QString url = env::getUrl() + "/login";
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));
    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}

void MainWindow::onBtnValitseCreditClicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::onBtnValitseDebitClicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::onBtnKirjauduUlosClicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::onBtnNostaRahaaClicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::onBtnTilitapahtumatClicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::onBtnTakaisinClicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::onBtnTakaisin2Clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::onBtnTakaisin3Clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::handleDLLSignal(QString s)
{
    ui->lineEdit->setText(s);
    //ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::handleClick()
{
    ptr_dll->show();
}

void MainWindow::checkAttachedAccounts()
{
    qDebug() << "checkAttachedAccounts()";

    QJsonObject sentData;
    sentData.insert("card", cardNo);

    QString url = env::getUrl() + "/getaccounts";
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // add token here

    accountCheckManager = new QNetworkAccessManager(this);
    connect(accountCheckManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(attachedAccountCheckSlot(QNetworkReply*)));

    accountCheckReply = accountCheckManager->post(request, QJsonDocument(sentData).toJson());
}

void MainWindow::onBtnKatsoTiedotClicked()
{
    QJsonObject sentData;
    sentData.insert("card", cardNo);

    QString url = env::getUrl() + "/viewprofile";
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    transferManager = new QNetworkAccessManager(this);
    connect(transferManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(profileDataSlot(QNetworkReply*)));

    reply = transferManager->post(request, QJsonDocument(sentData).toJson());
}
