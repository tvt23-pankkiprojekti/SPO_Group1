#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QDialog>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkRequest>


namespace Ui {
class transaction;
}

class transaction : public QDialog{
    Q_OBJECT
public:
    ~transaction();
    void setWebtoken(const QByteArray &newWebtoken);
    void deposit();
    void withdraw();
    void balance();
    void transactionHistory();
    void addTransaction();
private slots:
    //void depositSlot(QNetworkReply *reply);
    //void withdrawSlot(QNetworkReply *reply);
    //void balanceSlot(QNetworkReply *reply);
    //void historySlot(QNetworkReply *reply);
    void transactionSlot(QNetworkReply *reply);
private:

    QString id_account;
    QString amount;
    QString description;
    QByteArray webtoken;
    QNetworkAccessManager *getManager;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // TRANSACTION_H
