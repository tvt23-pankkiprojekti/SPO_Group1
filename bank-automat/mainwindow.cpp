#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_actionDEMO_triggered()
{
    qDebug()<<"DEMO1 kortti valittu valikosta";
    ui->labelKortinTila->setText("DEMO1 kortti luettu");
    ui->labelKortinNumero->setText("987654321");
}





void MainWindow::on_btnEnterPin_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_btnValitseCredit_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_btnValitseDebit_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btnKirjauduUlos_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_btnNostaRahaa_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}


void MainWindow::on_btnTilitapahtumat_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_btnTakaisin_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_btnTakaisin2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_btnTakaisin3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_btnKatsoTiedot_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

