#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
    accountInfo = new ProfileWindow;
    accountInfo->attachWindow(ui->stackedWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_actionDEMO_triggered()
{
    qDebug()<<"DEMO1 kortti valittu valikosta";
    ui->labelKortinTila->setText("DEMO1 kortti luettu");
    ui->labelKortinNumero->setText("987654321");
}

void MainWindow::on_btnEnterPin_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btnValitseCredit_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btnValitseDebit_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btnKirjauduUlos_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_btnNostaRahaa_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}


void MainWindow::on_btnTilitapahtumat_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_btnTakaisin_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_btnTakaisin2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_btnTakaisin3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_btnKatsoTiedot_clicked()
{
    QString cardNo = "060006F235";
    QJsonObject sentData;
    sentData.insert("card", cardNo);

    QString url = env::getUrl() + "/viewprofile";
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    transferManager = new QNetworkAccessManager(this);
    connect(transferManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(profileDataSlot(QNetworkReply*)));

    reply = transferManager->post(request, QJsonDocument(sentData).toJson());
}

