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
    //explicit transaction(QWidget *parent = nullptr);
    ~transaction();
    void setWebtoken(const QByteArray &newWebtoken);
    void deposit();
    void withdraw();
    void balance();
    void history();
private slots:
    //void action();
    void depositSlot(QNetworkReply *reply);
    //void withdrawSlot(QNetworkReply *reply);
    //void balanceSlot(QNetworkReply *reply);
    //void historySlot(QNetworkReply *reply);
    //void actionSlot(QNetworkReply *reply);
private:

    QString id_account;
    QString amount;
    QByteArray webtoken;
    QNetworkAccessManager *getManager;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // TRANSACTION_H
