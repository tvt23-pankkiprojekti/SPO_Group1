#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
#include <QSerialPort>
#include <QSerialPortInfo>
=======
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
>>>>>>> dcc5b237bc52011f8b7f0d43756056f036b4c8aa

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
    ~MainWindow();

public slots:
    void profileDataSlot(QNetworkReply *reply);

private slots:
    void onActionDEMOTriggered();
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
    void on_actionDEMO_triggered();
    void on_btnEnterPin_clicked();
    void on_btnValitseCredit_clicked();
    void on_btnValitseDebit_clicked();
    void on_btnKirjauduUlos_clicked();
    void on_btnNostaRahaa_clicked();
    void on_btnTilitapahtumat_clicked();
    void on_btnTakaisin_clicked();
    void on_btnTakaisin2_clicked();
    void on_btnTakaisin3_clicked();
    void on_btnKatsoTiedot_clicked();
    ProfileWindow *accountInfo;
    QNetworkAccessManager *transferManager;
    QNetworkReply *reply;
    QByteArray data;
};
#endif // MAINWINDOW_H
