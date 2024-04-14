#include "pincodeverify.h"
#include "dialog.h"

PincodeVerify::PincodeVerify(QObject *parent) : QObject(parent)
{

}

bool PincodeVerify::verifyPin(const QString &pin)
{
    // Call the appropriate function from the Pincode DLL to verify the pin
    // For example:
    bool isValid = PincodeDLL::verify(pin.toStdString());
    return isValid;
}
