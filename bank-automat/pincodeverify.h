#ifndef PINCODEVERIFY_H
#define PINCODEVERIFY_H

#include <QObject>

class PincodeVerify : public QObject
{
    Q_OBJECT
public:
    explicit PincodeVerify(QObject *parent = nullptr);
    bool verifyPin(const QString &pin); // Function to verify pin code
signals:

public slots:
};

#endif // PINCODEVERIFY_H
