#include "transactionHistory.h"
#include "env.h"

transactionHistory::transactionHistory(QWidget *parent): QDialog(parent)
{
   // tableView = new QTableView(this);
    //tableView->setObjectName("tableView");
}

transactionHistory::~transactionHistory()
{
}

void transactionHistory::attachWindow(QWidget *window)
{
    tableView = window->findChild<QTableView*>("tableView");
    if (!tableView) {
        qDebug() << "Error";
    }
}

int transactionHistory::addEvents(int pageNum)
{
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    int eventsOnPage = 10;
    int maxNum = ((json_array.size()-1)/eventsOnPage)+1;
    QStandardItemModel *table_model = new QStandardItemModel(eventsOnPage, 3);
    table_model->setHeaderData(0, Qt::Horizontal, QObject::tr("Amount"));
    table_model->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
    table_model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));

    qDebug()<<"arrayn koko:" << json_array.size();
    qDebug()<< "Viimeinen sivu: "<<maxNum;
    for (int row = (pageNum-1)*eventsOnPage; row < (pageNum * eventsOnPage); ++row) {
        qDebug()<<row;
        QJsonObject events = json_array[row].toObject();
        QStandardItem *amount = new QStandardItem(events["amount"].toString());
        table_model->setItem(row-((pageNum-1)*eventsOnPage), 0, amount);
        QStandardItem *description = new QStandardItem(events["description"].toString());
        table_model->setItem(row-((pageNum-1)*eventsOnPage), 1, description );
        QStandardItem *date = new QStandardItem(events["time"].toString());
        table_model->setItem(row-((pageNum-1)*eventsOnPage), 2, date);
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
    tableView->setModel(table_model);

    return maxNum;
}


void transactionHistory::getEventSlot(QByteArray data)
{
    response_data = data;
    addEvents(1);
}


