#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QMovie>
#include <QDialog>
#include <QFile>
#include <QDir>
#include <QJsonObject>
#include <QJsonDocument>
#include <QtNetwork>
#include <QNetworkRequest>
#include "profilewindow.h"
#include "dialog.h"
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

private slots:
    void profileDataSlot(QNetworkReply *reply);
    void attachedAccountCheckSlot(QNetworkReply *reply);
    void transactionEventsData(QNetworkReply *reply);
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
    void clearGifs();
    void displayGifsOnStartMenu();
    void handleClick();
    void onnextButtonclicked();
    void onpreviousButtonclicked();
    void checkPage();
    void cardScanned();
    void cardVerifySlot(QNetworkReply *reply);


private:
    Ui::MainWindow *ui;
    Dialog *ptr_dll;

    QString cardNo;
    QString accountNo;
    QString creditAccount, debitAccount;
    QString token;

    ProfileWindow *accountInfo;
    
    QNetworkAccessManager *transferManager;
    QNetworkAccessManager *transferManagerEvents;
    QNetworkAccessManager *loginManager;
    QNetworkAccessManager *accountCheckManager;
    QNetworkAccessManager *cardVerifyManager;
    
    QNetworkReply *reply;
    QNetworkReply *accountCheckReply;
    QNetworkReply *replyEvents;
    QSerialPort serialPort;
    
    QByteArray data;

    int currentPage = 0;
    int maxPage;

    QLabel *arro = nullptr;
    QLabel *arro2 = nullptr;
    
    transactionHistory * eventData;
    
    void checkAttachedAccounts();
};
#endif // MAINWINDOW_H
