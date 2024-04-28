#ifndef TRANSACTIONTWO_H
#define TRANSACTIONTWO_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkRequest>
#include <QMessageBox>
#include "env.h"


class transactiontwo
{
public:
    transactiontwo(QMainWindow *mwindow);

    void withdrawFunds(int amount, QString card, QString account, QString token);
    QString withdrawReplySlot(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;
    QNetworkReply *reply;

    QMainWindow *window;
};

#endif // TRANSACTIONTWO_H
