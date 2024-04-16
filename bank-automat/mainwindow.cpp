#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    cardNo = "060006E2E7";

    ui->setupUi(this);
    ptr_dll = new Dialog(this);
    connect(ptr_dll,SIGNAL(sendString(QString)),
            this,SLOT(handleDLLSignal(QString)));

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
    ui->stackedWidget->setCurrentIndex(1);
    accountInfo = new ProfileWindow;
    accountInfo->attachWindow(ui->stackedWidget);
}





void MainWindow::profileDataSlot(QNetworkReply *reply)
{
    data = reply->readAll();

    if (data.length() == 0 || data == "-4078") {
        qDebug() << "Tietoliikenneyhteysvika";
        reply->deleteLater();
        transferManager->deleteLater();
        return;
    }

    if (data == "false") {
        qDebug() << "Tietoa ei saatu";
        reply->deleteLater();
        transferManager->deleteLater();
        return;
    }

    ui->stackedWidget->setCurrentIndex(5);
    accountInfo->updateUserData(&data);

    reply->deleteLater();
    transferManager->deleteLater();
}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    data=reply->readAll();
    QMessageBox msgBox;
    qDebug()<<"response_data";
    if(data=="-4078" || data.length()==0){

        msgBox.setText("Virhe tietoyhteydessä");
        msgBox.exec();
    }
    else{
        if(data!="false"){
            //kirjautuminen onnistui
            /*mainMenu *objectStudentMenu=new StudentMenu(this);
            objectStudentMenu->setUsername(ui->lineEdit->text());
            objectStudentMenu->setWebToken(data);*/
            ui->stackedWidget->setCurrentIndex(1);
        }
        else{
            msgBox.setText("Tunnus ei täsmää");
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
    //ui->stackedWidget->setCurrentIndex(1);
    QString pin=ui->lineEdit->text();
    QJsonObject jsonObj;
    jsonObj.insert("pincode", pin);

    QString url = env::getUrl() + "/login";
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));
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
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::handleClick()
{
    ptr_dll->show();
}

void MainWindow::onBtnKatsoTiedotClicked()
{
    QJsonObject sentData;
    sentData.insert("card", cardNo);

    QString url = env::getUrl() + "/viewprofile";
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    transferManager = new QNetworkAccessManager(this);
    connect(transferManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(profileDataSlot(QNetworkReply*)));

    reply = transferManager->post(request, QJsonDocument(sentData).toJson());
}
