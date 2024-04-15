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
private slots:
    void action();
    void deposit();
    void withdraw();
    void balance();
    void history();
    void actionSlot(QNetworkReply *reply);
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
