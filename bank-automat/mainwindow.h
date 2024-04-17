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

private:
    Ui::MainWindow *ui;
    Dialog * ptr_dll;

    QString cardNo;
    QString accountNo;

    ProfileWindow *accountInfo;
    QNetworkAccessManager *transferManager;
    QNetworkAccessManager *loginManager;
    QNetworkAccessManager *accountCheckManager;
    QNetworkReply *reply;
    QNetworkReply *accountCheckReply;
    QByteArray data;

    void checkAttachedAccounts();
};
#endif // MAINWINDOW_H
