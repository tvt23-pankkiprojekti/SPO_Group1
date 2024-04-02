#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pinDial1_valueChanged(int pin1);
    void on_pinDial2_valueChanged(int pin2);
    void on_pinDial3_valueChanged(int pin3);
    void on_pinDial4_valueChanged(int pin4);

    void on_pushButton_2_clicked();


    void on_actionDEMO_triggered();




private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
