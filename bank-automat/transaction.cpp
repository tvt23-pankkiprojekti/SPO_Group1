#include "transaction.h"
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

void transaction::action(){
    QString site_url=env::getUrl();
    QNetworkRequest request((site_url));
    QByteArray actionToken="Bearer "+webtoken;
    request.setRawHeader(QByteArray("Authorization"),(actionToken));
    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(actionSlot(QNetworkReply*)));
    reply = getManager->get(request);
}
/*
 * ylempana tehty webtoken ja alhaalla luetaan json data network replysta
 * data voidaan parseta stringiksi kuten peppi/grades.cpp esimerkissa tehdaan
 * talla koodilla se on json arrayssa
 * */
void transaction::actionSlot(QNetworkReply *reply){
    response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    //QString action;
}
/* tässä vanhaa koodia tallessa
void transaction::deposit(){
    //otetaan yhteys serveriin
    QString site_url="https://simulation-bank.onrender.com/transaction/deposit";
    QNetworkRequest request((site_url));
    //webtoken alku nimellä depositToken
    QByteArray depositToken="Bearer "+webtoken;
    request.setRawHeader(QByteArray("Authorization"),(depositToken));
    //webToken loppu
    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(actionSlot(QNetworkReply*)));
    reply = getManager->get(request);
}
void transaction::withdraw(){
    //otetaan yhteys serveriin
    QString site_url="https://simulation-bank.onrender.com/transaction/withdraw";
    QNetworkRequest request((site_url));
    // webtoken alku nimellä withdrawToken
    QByteArray withdrawToken="Bearer "+webtoken;
    request.setRawHeader(QByteArray("Authorization"),(withdrawToken));
    //webToken loppu
    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(actionSlot(QNetworkReply*)));
    reply = getManager->get(request);
}
void transaction::balance(){
    //yhteys serveriin
    QString site_url="https://simulation-bank.onrender.com/transaction/balance";
    QNetworkRequest request((site_url));
    //webtoken alku nimellä balanceToken
    QByteArray balanceToken="Bearer "+webtoken;
    request.setRawHeader(QByteArray("Authorization"),(balanceToken));
    //webToken loppu
    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(actionSlot(QNetworkReply*)));
    reply = getManager->get(request);
}
*/
