#include "env.h"

env::env() {}

QString env::getUrl()
{
    return "http://localhost:3000/bankomat";
    //return "https://simulation-bank.onrender.com/bankomat";
}
