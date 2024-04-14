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
    QJsonArray names = dataUnpacked.array();
    //QJsonObject nam = names.;
    qDebug() << names[0];
    //descriptionLabels[0]->setText(names);
}
