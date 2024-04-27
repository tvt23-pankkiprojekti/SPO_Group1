#include "env.h"

env::env() {}

QString env::getUrl()
{
    return "http://localhost:3000/bankomat";
    //return "https://simulation-bank.onrender.com/bankomat";
}

QString env::gifFetch()
{
    return "C:/Personal Files/School/Period 4/R1-pankkiprojekti/SPO_Group1/bank-automat/arrow.gif";
    //insert your own file path here!
    //AND add bank-automat/env.cpp
}
