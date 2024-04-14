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

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            transactions[i][j] = new QTableWidgetItem;
        }
    }

    table = window->findChild<QTableWidget*>("transactionTable");
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
        transactions[0][i]->setText(transaction["amount"].toString());
        transactions[1][i]->setText(transaction["time"].toString());
        transactions[2][i]->setText(transaction["description"].toString());
        table->setItem(i, 0, transactions[0][i]);
        table->setItem(i, 1, transactions[1][i]);
        table->setItem(i, 2, transactions[2][i]);
    }
}
