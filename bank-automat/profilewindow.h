#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include <QJsonObject>
#include <QJsonDocument>
#include <QtNetwork>
#include <QNetworkRequest>

class ProfileWindow : public QWidget
{
public:
    ProfileWindow();
    void attachWindow(QWidget *window);
    void updateUserData(QByteArray *data);

private:
    QLabel *descriptionLabels[6];
    QLabel *transactionAmounts[5];
    QLabel *transactionDates[5];
    QLabel *transactionDescriptions[5];
    QLabel **allLabels[4][6] = {{ descriptionLabels, transactionAmounts, transactionDates, transactionDescriptions }};
    QByteArray data;
};

#endif // PROFILEWINDOW_H
