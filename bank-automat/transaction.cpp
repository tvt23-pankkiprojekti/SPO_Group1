#include "transaction.h"
//#include "mainwindow.h"
#include "mainwindow.cpp"
#include "env.h"
#include <QDialog>
#include <qstring.h>
#include <QtNetwork>
#include <QNetworkAccessManager>


transaction::~transaction(){
}

void transaction::setWebtoken(const QByteArray &newWebtoken){
    webtoken = newWebtoken;
}
/*
void transaction::actionSlot(QNetworkReply *reply){
    //yhteys serveriin id_accountin kanssa
    QString site_url=env::getUrl()+id_account;
    QNetworkRequest request((site_url));
    //webtoken alku
    QByteArray myToken="Bearer "+webtoken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //webToken loppu
    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(actionSlot(QNetworkReply*)));
    reply = getManager->get(request);
    if (reply->error() == QNetworkReply::NoError){
        QByteArray responseData = reply->readAll();
        QString responseString = QString::fromUtf8(responseData);
        qDebug() << "Response received:" << responseString;
    }
    else {
        qDebug() << "Error:" << reply->errorString();
    }
}
*/
void transaction::deposit(){
    //json objectiin syöttö
    QJsonObject sentData;
    sentData.insert("acc",id_account);
    sentData.insert("am", amount);
    //urlin asettaminen ja headeri
    QString site_url=env::getUrl()+"/transaction/deposit";
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //postaus
    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(depositSlot(QNetworkReply*)));
    reply = postManager->post(request, QJsonDocument(sentData).toJson());
}
void transaction::withdraw(){
    //otetaan yhteys serveriin id_account, withdraw ja summa
    QString site_url=env::getUrl()+"/transaction/withdraw/";
}
void transaction::balance(){
    //otetaan yhteys serveriin id_account, balance ja summa
    QString site_url=env::getUrl()+"/transaction/balance/";
}
void transaction::history(){
    //otetaan yhteys serveriin id_account ja history
    QString site_url=env::getUrl()+"/transaction/history";
}
