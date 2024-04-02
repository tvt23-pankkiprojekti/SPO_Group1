#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <tilinvalinta.h>

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


void MainWindow::on_pinDial1_valueChanged(int pin1)
{
    ui->pinValue1->display(pin1);

}
void MainWindow::on_pinDial2_valueChanged(int pin2)
{
    ui->pinValue2->display(pin2);

}
void MainWindow::on_pinDial3_valueChanged(int pin3)
{
    ui->pinValue3->display(pin3);

}
void MainWindow::on_pinDial4_valueChanged(int pin4)
{
    ui->pinValue4->display(pin4);

}

void MainWindow::on_pushButton_2_clicked()
{
    TilinValinta *objectTilinValinta=new TilinValinta();
    objectTilinValinta->open();
}

void MainWindow::on_actionDEMO_triggered()
{
    qDebug()<<"DEMO1 kortti valittu valikosta";
    ui->labelKortinTila->setText("DEMO1 kortti luettu");
    ui->labelKortinNumero->setText("987654321");
}




