#ifndef TRANSACTIONHISTORY_H
#define TRANSACTIONHISTORY_H
#include <QString>
#include <QDateTime>
#include <QList>
#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QStandardItem>
#include <QDialog>
#include <QLabel>
#include <QSize>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QTableView>


QT_BEGIN_NAMESPACE
namespace Ui {
class transactionHistory;
}
QT_END_NAMESPACE

class transactionHistory : public QDialog
{
    Q_OBJECT

public:
    explicit transactionHistory(QWidget *parent = nullptr);
    ~transactionHistory();

    void attachWindow(QWidget *window);
    void addEvents();

    void on_tableEvents_clicked(const QModelIndex &index);
    void on_pushButtonEvents_clicked();

    void getEventSlot(QByteArray data);

private:

    QTableView * tableEvents;

    QNetworkAccessManager *getManager;
    QByteArray response_data;

    QList<transactionHistory> eventList;

};

#endif // TRANSACTIONHISTORY_H
