#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QMainWindow>
#include <QLabel>

class ProfileWindow : public QWidget
{
public:
    ProfileWindow();
    void attachWindow(QWidget *window);
    void updateUserData(QJsonObject *data);

private:
    QLabel *descriptionLabels[4];
    QLabel *transactionAmounts[5];
    QLabel *transactionDates[5];
    QLabel *transactionDescriptions[5];
    QLabel **allLabels[4] = { descriptionLabels, transactionAmounts, transactionDates, transactionDescriptions };
};

#endif // PROFILEWINDOW_H
