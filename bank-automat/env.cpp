#include "env.h"

env::env() {}

QString env::getUrl()
{
    return "http://localhost:3000/bankomat";
    //return "https://simulation-bank.onrender.com/bankomat";
}

QString env::gifFetchArrows()
{
    return "C:/Users/jlesa/OneDrive/School content/Y1/Ohjelmistokehityksen projekti/SPO_Group1/bank-automat/arrow.gif";
}

QString env::gifFetchMoney()
{
    return "C:/Users/jlesa/OneDrive/School content/Y1/Ohjelmistokehityksen projekti/SPO_Group1/bank-automat/money.gif";
}
