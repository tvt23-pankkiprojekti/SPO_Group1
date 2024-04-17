#include "transaction.h"
//#include "mainwindow.h"
#include "mainwindow.cpp"
#include "env.h"
#include <QDialog>
#include <qstring.h>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QWidget>
/*
transaction::transaction(QWidget *parent){
    QDialog(parent),
}
*/
transaction::~transaction(){
}

void transaction::setWebtoken(const QByteArray &newWebtoken){
    webtoken = newWebtoken;
}

void transaction::depositSlot(QNetworkReply *reply){
    response_data=reply->readAll();
    qDebug()<<response_data;
}

void transaction::deposit(){
    //json objectiin syöttö
    QJsonObject depositToAccount;
    depositToAccount.insert("acc",id_account);
    depositToAccount.insert("am", amount);
    //urlin asettaminen ja headeri
    QString site_url=env::getUrl()+"/transaction/deposit";
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //postaus
    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(depositSlot(QNetworkReply*)));
    reply = postManager->post(request, QJsonDocument(depositToAccount).toJson());
}
void transaction::withdraw(){
    //otetaan yhteys serveriin id_account, withdraw ja summa
    //QString site_url=env::getUrl()+"/transaction/withdraw/";
}
void transaction::balance(){
    //otetaan yhteys serveriin id_account, balance ja summa
    //QString site_url=env::getUrl()+"/transaction/balance/";
}
void transaction::history(){
    //otetaan yhteys serveriin id_account ja history
    //QString site_url=env::getUrl()+"/transaction/history";
}
