#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QDialog>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtNetwork>
#include <QNetworkAccessManager>

namespace Ui {
class transaction;
}

class transaction : public QDialog{
    Q_OBJECT
public:
    explicit transaction(QWidget *parent = nullptr);
    ~transaction();
    void setWebtoken(const QByteArray &newWebtoken);
    void withdraw();
    void deposit();
    void balance();
private slots:
    void depositSlot(QNetworkReply *reply);
    void withdrawSlot(QNetworkReply *reply);
    void balanceSlot(QNetworkReply *reply);
private:
    QString id_account;
    QByteArray webtoken;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // TRANSACTION_H
