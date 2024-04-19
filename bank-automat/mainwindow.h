#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDialog>
#include <QFile>
#include <QDir>
#include "dialog.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QtNetwork>
#include <QNetworkRequest>
#include "profilewindow.h"
#include "env.h"
#include <QList>
#include "transactionHistory.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);


public slots:
    void profileDataSlot(QNetworkReply *reply);
    void transactionEventsData(QNetworkReply *reply);


private slots:
    void loginSlot(QNetworkReply *reply);
    void onBtnEnterPinClicked();
    void onBtnValitseCreditClicked();
    void onBtnValitseDebitClicked();
    void onBtnKirjauduUlosClicked();
    void onBtnNostaRahaaClicked();
    void onBtnTilitapahtumatClicked();
    void onBtnTakaisinClicked();
    void onBtnTakaisin2Clicked();
    void onBtnTakaisin3Clicked();
    void onBtnKatsoTiedotClicked();
    void handleDLLSignal(QString);
    void handleClick();
    void onnextButtonclicked();
    void onpreviousButtonclicked();
    void checkPage();

private:
    Ui::MainWindow *ui;
    Dialog * ptr_dll;

    QString cardNo;
    QString idAccount;
    QString token;

    ProfileWindow *accountInfo;
    QNetworkAccessManager *transferManager;
    QNetworkAccessManager *transferManagerEvents;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QNetworkReply *replyEvents;
    QByteArray data;
    transactionHistory *eventData;

    int currentPage = 0;
    int maxPage;


};
#endif // MAINWINDOW_H
