#include "mainwindow.h"
#include "ui_mainwindow.h"

/*Initial setup
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _serialPort(nullptr)
{
    cardNo = "";
    accountNo = "";
    debitAccount = "";
    creditAccount = "";
    token = "";
    currentPage = 1;
    maxPage = 1;

    ui->setupUi(this);

    ptr_dll = new Dialog(this);

    ui->setupUi(this);
    loadPorts();

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
    connect(ui->btnSerialPortsInfo, SIGNAL(clicked()), this, SLOT(onBtnSerialPortsInfoclicked()));
    connect(ui->btnOpenPort, SIGNAL(clicked()), this, SLOT(onBtnOpenPortclicked()));

    //transaction window buttons
    connect(ui->muuSumma, SIGNAL(clicked()), this, SLOT(muuSummaClicked()));
    connect(ui->N20, SIGNAL(clicked()), this, SLOT(onN20Clicked()));
    connect(ui->N40, SIGNAL(clicked()), this, SLOT(onN40Clicked()));
    connect(ui->N50, SIGNAL(clicked()), this, SLOT(onN50Clicked()));
    connect(ui->N100, SIGNAL(clicked()), this, SLOT(onN100Clicked()));
    connect(ui->clearBtn, SIGNAL(clicked()), this, SLOT(clearSum()));
    connect(ui->lessBtn, SIGNAL(clicked()), this, SLOT(onLessButtonClicked()));
    connect(ui->moreBtn, SIGNAL(clicked()), this, SLOT(onMoreButtonClicked()));
    //connect(ui->withdrawBtn,SIGNAL(clicked(bool)), this,SLOT(withdrawClickHandler()));

    ui->stackedWidget->setCurrentIndex(2);

    //displayGifsOnStartMenu();
    hideLessAndMoreButtons();

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

void MainWindow::displayGifsOnStartMenu()
{
    QMovie *movie = new QMovie("C:/Personal Files/School/Period 4/R1-pankkiprojekti/SPO_Group1/bank-automat/arrow.gif");

        arro = new QLabel(this);
        arro->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        arro->setGeometry(145, 350, 250, 250);
        arro->setScaledContents(true);
        arro->setMovie(movie);

        arro2 = new QLabel(this);
        arro2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        arro2->setGeometry(650, 355, 250, 250);
        arro2->setScaledContents(true);
        arro2->setMovie(movie);

        movie->start();

    qDebug() << "Gifs working";
}

void MainWindow::clearGifs()
{
    arro->movie()->stop();
    delete arro;
    arro = nullptr;

    arro2->movie()->stop();
    delete arro2;
    arro2 = nullptr;
}

void MainWindow::loadPorts()
{
    foreach (auto &port, QSerialPortInfo::availablePorts()) {
        ui->cmbPorts->addItem(port.portName());
    }
}

/* Misceallaneous UI buttons
 */
void MainWindow::onBtnValitseCreditClicked()
{
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

void MainWindow::onBtnNostaRahaaClicked()
{
    ui->stackedWidget->setCurrentIndex(3);
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


/* Setting up the serial port to read incoming cards
 */
void MainWindow::onBtnSerialPortsInfoclicked()
{

}

void MainWindow::onBtnOpenPortclicked()
{
    if (_serialPort != nullptr) {
        _serialPort->close();
        delete _serialPort;
    }
    _serialPort = new QSerialPort(this);
    _serialPort->setPortName(ui->cmbPorts->currentText());
    _serialPort->setBaudRate(QSerialPort::Baud9600);
    _serialPort->setDataBits(QSerialPort::Data8);
    _serialPort->setParity(QSerialPort::NoParity);
    _serialPort->setStopBits(QSerialPort::OneStop);
    if (_serialPort->open(QIODevice::ReadOnly)) {
        /*QMessageBox msgBox(this);
        msgBox.setWindowTitle("Result");
        msgBox.setText("Port open");
        setMessageBoxStyles(msgBox);
        msgBox.exec();*/
        connect(_serialPort, &QSerialPort::readyRead, this, &MainWindow::readData);
    } else {
        QMessageBox::critical(this, "Port Error", "Porttia ei voinut avata...");
    }
}

void MainWindow::readData()
{
    if (!_serialPort->isOpen()) {
        //QMessageBox::critical(this, "Port Error", "Portti ei auki");
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Port Error");
        msgBox.setText("Port closed");
        setMessageBoxStyles(msgBox);
        msgBox.exec();
        return;
    }
    auto data = _serialPort->readAll();
    data.replace("\r\n-", "");
    data.replace("\r\n>", "");
    //ui->labelKortinNumero->setText(QString(data));
    qDebug() << data;
    cardNo = data;

    verifyCard();
}


/*
 */
void MainWindow::verifyCard()
{
    qDebug() << "verifyCard()";

    QJsonObject sentData;
    sentData.insert("card", cardNo);

    QString url = env::getUrl() + "/verifycard";
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    cardVerificationManager = new QNetworkAccessManager(this);
    connect(cardVerificationManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(cardVerificationSlot(QNetworkReply*)));

    accountCheckReply = cardVerificationManager->post(request, QJsonDocument(sentData).toJson());
}

void MainWindow::cardVerificationSlot(QNetworkReply *cardVerificationReply)
{
    qDebug() << "cardVerificationSlot()";
    QByteArray data = cardVerificationReply->readAll();
    QMessageBox msgBox;

    if(data.length()==0 || data == "-4078"){
        qDebug()<<"Tietoliikenneyhteysvika";
        msgBox.setText("Network error");
        setMessageBoxStyles(msgBox);
        msgBox.exec();
        cardVerificationReply->deleteLater();
        cardVerificationManager->deleteLater();
        return;
    }

    if (data == "false") {
        qDebug() << "Tietoa ei saatu";
        msgBox.setText("Invalid card");
        setMessageBoxStyles(msgBox);
        msgBox.exec();
        cardVerificationReply->deleteLater();
        cardVerificationManager->deleteLater();
        return;
    }

    handleClick();

    cardVerificationReply->deleteLater();
    cardVerificationManager->deleteLater();
}


/* Login
 */
void MainWindow::handleClick()
{
    ptr_dll->show();
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

    //WEBTOKEN ALKU
    QByteArray myToken="Bearer "+token.toUtf8();
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));
    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    data = reply->readAll();
    //qDebug()<<data;
    QMessageBox msgBox;
    if(data=="-4078" || data.length()==0){
        msgBox.setText("Network error");
        setMessageBoxStyles(msgBox);
        msgBox.exec();
    }
    else{
        if(data!="false"){
            qDebug() << data;
            token = data;
            qDebug() << "loginSlot(), data wasn't false";
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

/* Fetching data on the accounts attached to the card & if there are multiple,
 * bringing up the credit-debit choice window
 */
void MainWindow::checkAttachedAccounts()
{
    qDebug() << "checkAttachedAccounts()";

    QJsonObject sentData;
    sentData.insert("card", cardNo);

    QString url = env::getUrl() + "/getaccounts";
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray myToken="Bearer "+token.toUtf8();
    request.setRawHeader(QByteArray("Authorization"),(myToken));

    accountCheckManager = new QNetworkAccessManager(this);
    connect(accountCheckManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(attachedAccountCheckSlot(QNetworkReply*)));

    accountCheckReply = accountCheckManager->post(request, QJsonDocument(sentData).toJson());
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
    else if(data == "false"){
        msgBox.setText("Data acquisition error");
        setMessageBoxStyles(msgBox);
        msgBox.exec();
    }
    else {
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


/* Viewing the user's profile (card & account data + some of the latest transactions)
 */
void MainWindow::onBtnKatsoTiedotClicked()
{
    QJsonObject sentData;
    sentData.insert("card", cardNo);
    sentData.insert("account", accountNo);

    QString url = env::getUrl() + "/viewprofile";
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray myToken="Bearer "+token.toUtf8();
    request.setRawHeader(QByteArray("Authorization"),(myToken));

    transferManager = new QNetworkAccessManager(this);
    connect(transferManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(profileDataSlot(QNetworkReply*)));

    reply = transferManager->post(request, QJsonDocument(sentData).toJson());
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


/* Viewing the entire transaction history of the current account
 */
void MainWindow::onBtnTilitapahtumatClicked()
{
    ui->previousButton->setVisible(false);
    maxPage = 1;
    currentPage = 1;
    QJsonObject sentData;
    sentData.insert("idaccount", accountNo);
    sentData.insert("card", cardNo);

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

/* Withdrawing funds
 */


//buttons
void MainWindow::muuSummaClicked()
{
    clearSum();
    ui->lessBtn->setVisible(true);
    ui->moreBtn->setVisible(true);
}

void MainWindow::onN20Clicked()
{
    hideLessAndMoreButtons();
    updateLabelWithdrawSum(20);
}

void MainWindow::onN40Clicked()
{
    hideLessAndMoreButtons();
    updateLabelWithdrawSum(40);
}

void MainWindow::onN50Clicked()
{
    hideLessAndMoreButtons();
    updateLabelWithdrawSum(50);
}

void MainWindow::onN100Clicked()
{
    hideLessAndMoreButtons();
    updateLabelWithdrawSum(100);
}

void MainWindow::clearSum()
{
    ui->lessBtn->setVisible(false);
    ui->moreBtn->setVisible(false);
    ui->labelWithdrawSum->setText("0€");
}

void MainWindow::updateLabelWithdrawSum(int value)
{
    ui->labelWithdrawSum->setText(QString::number(value) + "€");
}

void MainWindow::hideLessAndMoreButtons()
{
    ui->lessBtn->setVisible(false);
    ui->moreBtn->setVisible(false);
}

void MainWindow::onMoreButtonClicked()
{
    QString currentText = ui->labelWithdrawSum->text();

    int currentValue = currentText.replace("€", "").toInt();
    int newValue = currentValue + 10;

    ui->labelWithdrawSum->setText(QString::number(newValue) + "€");
}

void MainWindow::onLessButtonClicked()
{
    QString currentText = ui->labelWithdrawSum->text();

    int currentValue = currentText.replace("€", "").toInt();
    int newValue = currentValue - 10;

    // Ensure newValue doesn't go below 0
    if(newValue < 0)
        newValue = 0;

    ui->labelWithdrawSum->setText(QString::number(newValue) + "€");
}


/* Logout
 */
void MainWindow::onBtnKirjauduUlosClicked()
{
    cardNo = "";
    accountNo = "";
    debitAccount = "";
    creditAccount = "";
    token = "";
    currentPage = 1;
    maxPage = 1;
    ui->stackedWidget->setCurrentIndex(0);
}
