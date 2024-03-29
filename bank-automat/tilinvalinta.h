#ifndef TILINVALINTA_H
#define TILINVALINTA_H

#include <QDialog>

namespace Ui {
class TilinValinta;
}

class TilinValinta : public QDialog
{
    Q_OBJECT

public:
    explicit TilinValinta(QWidget *parent = nullptr);
    ~TilinValinta();

private slots:
    void on_pushButton_clicked();

    void on_btnValitseCredit_clicked();

    void on_btnValitseDebit_clicked();

private:
    Ui::TilinValinta *ui;
};

#endif // TILINVALINTA_H
