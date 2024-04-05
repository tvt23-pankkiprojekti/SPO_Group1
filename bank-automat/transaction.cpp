#include "transaction.h"
#include <QDialog>
#include <qstring.h>

transaction::~transaction(){
}

void transaction::setWebtoken(const QByteArray &newWebtoken){
    webtoken = newWebtoken;
}

void transaction::deposit(){
    //otetaan yhteys serveriin
    QString site_url="https://simulation-bank.onrender.com/transaction/deposit";
    QNetworkRequest request((site_url));
    //webtoken alku nimellä depositToken
    QByteArray depositToken="Bearer "+webtoken;
    request.setRawHeader(QByteArray("Authorization"),(depositToken));
    //webToken loppu
    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(depositSlot(QNetworkReply*)));
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
    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(withdrawSlot(QNetworkReply*)));
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
    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(balanceSlot(QNetworkReply*)));
}
