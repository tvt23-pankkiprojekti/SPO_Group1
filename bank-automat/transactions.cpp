#include "transactions.h"

transactions::transactions() {}


void transactions::addTransactions()
{
    transactions obj;
    obj.setAccount(); obj.setAmount(); transactList.append(obj);
}


void MainWindow::on_pushButtonTapaht_clicked()
{
    QStandardItemModel *table_model = new QStandardItemModel(transactList.size(),2);
    table_model->setHeaderData(0, Qt::Horizontal, QObject::tr("Tilinumero"));
    table_model->setHeaderData(1, Qt::Horizontal, QObject::tr("Summa"));
    table_model->setHeaderData(2, Qt::Horizontal, QObject::tr("Tyyppi"));
    table_model->setHeaderData(3, Qt::Horizontal, QObject::tr("PVM"));

    for (int row = 0; row < transactList.size(); ++row) {
        QStandardItem *account = new QStandardItem((transactList[row].getAccount()));
        table_model->setItem(row, 0, account);
        QStandardItem *amount = new QStandardItem((transactList[row].getAmount()));
        table_model->setItem(row, 1, amount);
        QStandardItem *type = new QStandardItem((transactList[row].getType()));
        table_model->setItem(row, 2, type);
        QStandardItem *date = new QStandardItem((transactList[row].getDate()));
        table_model->setItem(row, 3, date);
    }

   ui->tableTransactions->setModel(table_model);

}

