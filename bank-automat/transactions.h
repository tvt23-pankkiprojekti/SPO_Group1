#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <QString>
#include <QDateTime>
#include <QList>
#include <QMainWindow>

class transactions
{
public:
    transactions();
    ~transactions();
    void addTransactions();

    QString getAccount() const;
    void setAccount(const QString& acc);
    QString getAmount() const;
    void setAmount(const QString& amt);
    QString getType() const;
    void setType(const QString& typ);
    QDateTime getDate() const;
    void setDate(const QDateTime& dt);

    void on_tableTransactions_clicked(const QModelIndex &index);
    void on_pushButtonTapaht_clicked();

private:
    QString account;
    QString amount;
    QString type;
    QDateTime date;


class MainWindow : public QMainWindow{

private:
    QList<transactions> transactList;

};

#endif // TRANSACTIONS_H
