#include "transaction.h"
//#include "mainwindow.h"
#include "mainwindow.cpp"
#include "env.h"
#include <QDialog>
#include <qstring.h>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QWidget>

transaction::~transaction(){
}

void transaction::setWebtoken(const QByteArray &newWebtoken){
    webtoken = newWebtoken;
}

void transaction::transactionSlot(QNetworkReply *reply){
    response_data=reply->readAll();
    qDebug()<<response_data;
    qDebug()<<"transaction_response_data";
    //if tarkastukset aka yhteysvika ja tietoa ei saatu viat tähän väliin
}

void transaction::deposit(){
    //json objectiin syöttö
    QJsonObject depositObj;
    depositObj.insert("acc",id_account);
    depositObj.insert("am", amount);
    //urlin asettaminen ja headeri
    QString site_url=env::getUrl()+"/transaction/deposit";
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //depositObj postaus
    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(transactionSlot(QNetworkReply*)));
    reply = postManager->post(request, QJsonDocument(depositObj).toJson());
}
void transaction::withdraw(){
    //json objectiin syöttö
    QJsonObject withdrawObj;
    withdrawObj.insert("acc",id_account);
    withdrawObj.insert("am", amount);
    //urlin asettaminen ja headeri
    QString site_url=env::getUrl()+"/transaction/withdraw";
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //depositObj postaus
    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(transactionSlot(QNetworkReply*)));
    reply = postManager->post(request, QJsonDocument(withdrawObj).toJson());
}
void transaction::balance(){
    //json objectiin syöttö
    QJsonObject balanceObj;
    balanceObj.insert("acc",id_account);
    //urlin asettaminen ja headeri
    QString site_url=env::getUrl()+"/transaction/balance";
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //depositObj postaus
    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(transactionSlot(QNetworkReply*)));
    reply = postManager->post(request, QJsonDocument(balanceObj).toJson());
}
void transaction::transactionHistory(){
    //json objectiin syöttö
    QJsonObject historyObj;
    historyObj.insert("acc",id_account);
    //urlin asettaminen ja headeri
    QString site_url=env::getUrl()+"/transaction/history";
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //depositObj postaus
    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(transactionSlot(QNetworkReply*)));
    reply = postManager->post(request, QJsonDocument(historyObj).toJson());
}
void transaction::addTransaction(){
    QJsonObject addObj;
    addObj.insert("acc", id_account);
    addObj.insert("am", amount);
    addObj.insert("des", description);
    //urlin asettaminen ja headeri
    QString site_url=env::getUrl()+"/transaction/adddTransaction";
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //depositObj postaus
    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(transactionSlot(QNetworkReply*)));
    reply = postManager->post(request, QJsonDocument(addObj).toJson());
}
