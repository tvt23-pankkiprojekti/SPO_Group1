#include "mainmenu.h"
#include "tilinvalinta.h"
#include "ui_tilinvalinta.h"

TilinValinta::TilinValinta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TilinValinta)
{
    ui->setupUi(this);
}

TilinValinta::~TilinValinta()
{
    qDebug()<<"TilinValinta olio tuhottiin";
    delete ui;
}

void TilinValinta::on_pushButton_clicked()
{

}


void TilinValinta::on_btnValitseCredit_clicked()
{
    MainMenu *objectMainMenu=new MainMenu();
    objectMainMenu->open();
}


void TilinValinta::on_btnValitseDebit_clicked()
{
    MainMenu *objectMainMenu=new MainMenu();
    objectMainMenu->open();
}

