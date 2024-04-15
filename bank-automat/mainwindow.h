#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

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

public slots:
    void profileDataSlot(QNetworkReply *reply);

private slots:
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

    ProfileWindow *accountInfo;
    QNetworkAccessManager *transferManager;
    QNetworkReply *reply;
    QByteArray data;
};
#endif // MAINWINDOW_H
