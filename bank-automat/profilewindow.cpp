#include "profilewindow.h"

ProfileWindow::ProfileWindow() {}

void ProfileWindow::attachWindow(QWidget *window)
{
    descriptionLabels[0] = window->findChild<QLabel*>("displayAccountOwner");
    descriptionLabels[1] = window->findChild<QLabel*>("displayAccountID");
    descriptionLabels[2] = window->findChild<QLabel*>("displayAccountOwnerID");
    descriptionLabels[3] = window->findChild<QLabel*>("displayCardID");
    descriptionLabels[4] = window->findChild<QLabel*>("displayCardOwner");
    descriptionLabels[5] = window->findChild<QLabel*>("displayCardOwnerID");
    for (int i = 0; i < 5; i++) {
        QString amountName = "transactionAmount" + QString::number(i + 1);
        QString dateName = "transactionDate" + QString::number(i + 1);
        QString descriptionName = "transactionDescription" + QString::number(i + 1);
        transactionAmounts[i] = window->findChild<QLabel*>(amountName);
        transactionDates[i] = window->findChild<QLabel*>(dateName);
        transactionDescriptions[i] = window->findChild<QLabel*>(descriptionName);
        transactionAmounts[i]->setText("-");
        transactionDates[i]->setText("-");
        transactionDescriptions[i]->setText("-");
    }
}

void ProfileWindow::updateUserData(QByteArray *data)
{
    QJsonDocument dataUnpacked = QJsonDocument::fromJson(*data);
    QJsonArray array = dataUnpacked.array();
    QJsonObject info = array[0].toObject();
    descriptionLabels[0]->setText(info["account_owner"].toString());
    descriptionLabels[1]->setText(info["id_account"].toString());
    descriptionLabels[2]->setText(QString::number(info["id_account_owner"].toInt()));
    descriptionLabels[3]->setText(info["id_card"].toString());
    descriptionLabels[4]->setText(info["card_owner"].toString());
    descriptionLabels[5]->setText(QString::number(info["id_card_owner"].toInt()));

    for (int i = 0; i < 5; i++) {
        QJsonObject transaction = array[i + 1].toObject();
        transactionAmounts[i]->setText(transaction["amount"].toString());
        transactionDates[i]->setText(transaction["time"].toString());
        transactionDescriptions[i]->setText(transaction["description"].toString());
    }
}
