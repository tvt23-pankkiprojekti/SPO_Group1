#include "env.h"

env::env() {}

QString env::getUrl()
{
    //return "http://localhost:3000/bankomat";
    return "https://simulation-bank.onrender.com/bankomat";
}

QString env::gifFetch()
{
    return "C:/Users/jlesa/OneDrive/School content/Y1/Ohjelmistokehityksen projekti/SPO_Group1/bank-automat/arrow.gif";
}
