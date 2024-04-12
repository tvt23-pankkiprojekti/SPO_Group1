#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

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

private slots:



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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
