#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    cardNo = "060006E2E7";
    debitAccount = "";
    creditAccount = "";

    ui->setupUi(this);

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
    connect(ui->previousButton, SIGNAL(clicked()), this, SLOT(onpreviousButtonclicked()));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(onnextButtonclicked()));

    connect(ui->btn,SIGNAL(clicked(bool)),
            this,SLOT(handleClick()));
    ui->stackedWidget->setCurrentIndex(0);
    displayGifsOnStartMenu();
    accountInfo = new ProfileWindow;
    accountInfo->attachWindow(ui->stackedWidget);

    eventData = new transactionHistory(this);
    eventData->attachWindow(ui->stackedWidget);
}

void setMessageBoxStyles(QMessageBox& msgBox) {
    msgBox.setStyleSheet(
        "QDialog { background-color: #36548f; color: #ffffff; }"
        "QLabel { font-weight: bold; font-size: 15px; background-color: transparent; color: #ffffff; }"
        "QPushButton { font-weight: bold; font-size: 10px; background-color: #426ca4; color: #ffffff; border-style: solid; border-width: 1px; border-radius: 5px; border-color: transparent; padding: 10px; min-width: 20px; }"
        "QPushButton:hover { background-color: #54a6cc; color: #ffffff; border-style: solid; border-width: 3px; border-radius: 5px; border-color: #36548f; padding: 10px; min-width: 20px; }"
        "QPushButton:pressed { background-color: #284070; color: #ffffff; border-style: solid; border-width: 3px; border-radius: 5px; border-color: transparent; padding: 10px; min-width: 20px; }"
        );
}

void MainWindow::displayGifsOnStartMenu() {
    if (ui->stackedWidget->currentIndex() != 0)
        return;

    QMovie *movie = new QMovie("C:/Users/nidac/Documents/projektipankkiautomaatti/Pankki_koodit/SPO_Group1/bank-automat/arrow.gif");

    if (!arro) {
        arro = new QLabel(this);
        arro->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        arro->setGeometry(145, 350, 250, 250);
        arro->setScaledContents(true);
        arro->setMovie(movie);
    }

    if (!arro2) {
        arro2 = new QLabel(this);
        arro2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        arro2->setGeometry(650, 355, 250, 250);
        arro2->setScaledContents(true);
        arro2->setMovie(movie);
    }

    movie->start();
}

void MainWindow::clearGifs() {
    if (arro) {
        arro->movie()->stop();
        delete arro;
        arro = nullptr;
    }

    if (arro2) {
        arro2->movie()->stop();
        delete arro2;
        arro2 = nullptr;
    }
}

void MainWindow::profileDataSlot(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QMessageBox msgBox;

    if (data.length() == 0 || data == "-4078") {
        qDebug() << "Tietoliikenneyhteysvika";
        msgBox.setText("Network error");
        setMessageBoxStyles(msgBox);
        msgBox.exec();
        reply->deleteLater();
        transferManager->deleteLater();
        return;
    }

    if (data == "false") {
        qDebug() << "Virhe tietojen hankinnassa";
        msgBox.setText("Data acquisition error");
        setMessageBoxStyles(msgBox);
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
        setMessageBoxStyles(msgBox);
        msgBox.exec();
    }
    else {
        if(data == "false"){
            msgBox.setText("Data acquisition error");
            setMessageBoxStyles(msgBox);
            msgBox.exec();
        }

        QJsonDocument dataUnpacked = QJsonDocument::fromJson(data);
        //qDebug() << dataUnpacked;

        QJsonArray array = dataUnpacked.array();

        if (array.size() < 1) {
            msgBox.setText("No accounts attached to this card");
            setMessageBoxStyles(msgBox);
            msgBox.exec();
        }
        else if (array.size() > 1) {
            //qDebug() << "Tilin tyyppi: " << array[0].toObject()["type"].toInt();
            if (array[0].toObject()["type"].toInt() == 0) {
                creditAccount = array[0].toObject()["id_account"].toString();
                debitAccount = array[1].toObject()["id_account"].toString();
                //qDebug() << "Credit-tili:" << creditAccount << ", debit-tili:" << debitAccount;
            }
            else {
                creditAccount = array[1].toObject()["id_account"].toString();
                debitAccount = array[0].toObject()["id_account"].toString();

                //qDebug() << "Credit-tili:" << creditAccount << ", debit-tili:" << debitAccount;
            }
            ui->stackedWidget->setCurrentIndex(1);
        }
        else {
            accountNo = array[0].toObject()["id_account"].toString();
            ui->stackedWidget->setCurrentIndex(2);
        }
    }

    accountCheckReply->deleteLater();
    accountCheckManager->deleteLater();
}

void MainWindow::transactionEventsData(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();

    if(data.length()==0 || data == "-4078"){
        qDebug()<<"Tietoliikenneyhteysvika";
        reply->deleteLater();
        transferManagerEvents->deleteLater();
        return;
    }

    if (data == "false") {
        qDebug() << "Tietoa ei saatu";
        reply->deleteLater();
        transferManagerEvents->deleteLater();
        return;
    }

    ui->stackedWidget->setCurrentIndex(4);
    eventData->getEventSlot(data);

    maxPage = eventData->addEvents(currentPage);
    checkPage();


    replyEvents->deleteLater();
    transferManagerEvents->deleteLater();
}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    data = reply->readAll();
    qDebug()<<data;
    QMessageBox msgBox;
    qDebug()<<data;
    if(data=="-4078" || data.length()==0){
        msgBox.setText("Network error");
        setMessageBoxStyles(msgBox);
        msgBox.exec();
    }
    else{
        if(data!="false"){

            msgBox.setText("Kirjautunut");
            //kirjautuminen onnistui


            qDebug() << "loginSLot(), data wasn't false";
            checkAttachedAccounts();
            clearGifs();
        }
        else{
            msgBox.setText("Incorrect password");
            setMessageBoxStyles(msgBox);
            msgBox.exec();
        }
    }
    reply->deleteLater();
    loginManager->deleteLater();
}

void MainWindow::onBtnEnterPinClicked()
{
    qDebug()<<"enter clicked";


    //ui->stackedWidget->setCurrentIndex(1);


    QString pin = ptr_dll->getPincode();
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


    //qDebug() << "Credit valittu";


    //qDebug() << "Credit valittu";

    accountNo = creditAccount;
    creditAccount = "";
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::onBtnValitseDebitClicked()
{
    //qDebug() << "Debit valittu";

    accountNo = debitAccount;
    debitAccount = "";
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
    ui->previousButton->setVisible(false);
    maxPage = 1;
    currentPage = 1;
    QJsonObject sentData;
    sentData.insert("idaccount", accountNo);

    QString url = env::getUrl() + "/viewtransactions";
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    QByteArray myToken="Bearer "+token.toUtf8();
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    transferManagerEvents = new QNetworkAccessManager(this);
    connect(transferManagerEvents, SIGNAL(finished(QNetworkReply*)), this, SLOT(transactionEventsData(QNetworkReply*)));

    replyEvents = transferManagerEvents->post(request, QJsonDocument(sentData).toJson());

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

/*void MainWindow::handleDLLSignal(QString s)
{
    //ui->lineEdit->setText(s);
    ui->stackedWidget->setCurrentIndex(1);
}*/

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
    sentData.insert("account", accountNo);

    QString url = env::getUrl() + "/viewprofile";
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    transferManager = new QNetworkAccessManager(this);
    connect(transferManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(profileDataSlot(QNetworkReply*)));

    reply = transferManager->post(request, QJsonDocument(sentData).toJson());
}

void MainWindow::onpreviousButtonclicked()
{
    if (currentPage > 1) {
        currentPage--;
        maxPage = eventData->addEvents(currentPage);
    }

    checkPage();
}

void MainWindow::checkPage()
{
    if (currentPage == 1) {
        ui->previousButton->setVisible(false);
    }
    else {
        ui->previousButton->setVisible(true);
    }

    if (currentPage == maxPage) {
        ui->nextButton->setVisible(false);
    }
    else {
        ui->nextButton->setVisible(true);
    }
}


void MainWindow::onnextButtonclicked()
{
    if (currentPage <= maxPage) {
        currentPage++;
        maxPage = eventData->addEvents(currentPage);
    }

    qDebug()<<maxPage;

    checkPage();
}
