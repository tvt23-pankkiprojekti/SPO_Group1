#include "transactionHistory.h"
#include "env.h"
#include "ui_mainwindow.h"

transactionHistory::transactionHistory(QWidget *parent): QDialog(parent)
{}
transactionHistory::~transactionHistory()
{
}

void transactionHistory::attachWindow(QWidget *window)
{
    tableEvents= window->findChild<QTableView*>("tableEvents");
}

void transactionHistory::addEvents()
{
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    int max_events = qMin(json_array.size(), 10);
    QStandardItemModel *table_model = new QStandardItemModel(max_events,3);
    table_model->setHeaderData(0, Qt::Horizontal, QObject::tr("Amount"));
    table_model->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
    table_model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));

    qDebug()<<"virhe 1";
    for (int row = 0; row < max_events; ++row) {
    qDebug()<<row;
        QJsonObject events = json_array[row].toObject();
        QStandardItem *amount = new QStandardItem(events["amount"].toString());
        table_model->setItem(row, 0, amount);
        QStandardItem *description = new QStandardItem(events["description"].toString());
        table_model->setItem(row, 1, description );
        QStandardItem *date = new QStandardItem(events["time"].toString());
        table_model->setItem(row, 2, date);
    }

   /* QString event;

    event="Tilinumero | summa | Tyyppi | PVM\r";
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        event+=json_obj["id_account"].toString()+" | ";
        event+=QString::number(json_obj["amount"].toInt())+" | ";
        event+=QString::number(json_obj["description"].toInt())+" | ";
        event+=json_obj["time"].toString();
        event+="\r";
    }*/
    qDebug()<<"virhe 2";
    tableEvents->setModel(table_model);

}



void transactionHistory::on_pushButtonEvents_clicked()
{


}

void transactionHistory::getEventSlot(QByteArray data)
{
    response_data = data;
    addEvents();
}


