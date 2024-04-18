const account = require('../../models/account_model');
const card = require('../../models/card_model');
const userdata = require('./userdata');
const procedure = require('../../models/procedure_model');

function newServicesWindow(request, response) {
    userdata.getUserData(request, response, function(user, cards, accounts) {
        response.render('newservices', {accounts: accounts, cards: cards});
    });
}

function openDebitCard(request, response) {
    findFreeCardID(request, response, 0, function(cardID) {
        let pin = randomizePin();
        let data = {
            'id_user': request.cookies['simulbankuserid'],
            'id_card': cardID,
            'id_account': request.body['account'],
            'pincode': pin
        };

        procedure.addNewCard(data, function(err, result) {
            if (err) {
                response.render('getcard', {error: "Something went wrong"});
                console.log(err);
            }
            else {
                response.render('getcard', {newcard: "Your debit card was succesfully created: ID " + cardID + ", PIN " + pin + "." });
            }
        });
    });
}

function openCreditCard(request, response) {    
    findFreeCardID(request, response, 0, function(cardID) {
        findFreeAccountID(request, response, 0, function(accountID) {
            let pin = randomizePin();
            let data = {
                'id_user': request.cookies['simulbankuserid'],
                'id_card': cardID,
                'id_account': accountID,
                'pincode': pin,
                'credit_limit': 3000.00
            };

            procedure.addCreditCardAndAccount(data, function(err, result) {
                if (err) {
                    response.render('getcard', {error: "Something went wrong"});
                    console.log(err);
                }
                else {
                    response.render('getcard', {newcard: "Your credit card was succesfully created: ID " + cardID + ", PIN " + pin + "." });
                }
            });
        });
    });
}
/* 
*/
function openAccount(request, response, accountType, next) {
    findFreeAccountID(request, response, 0, function(accountID) {
        let data = {
            'id_account': accountID,
            'id_user': request.cookies['simulbankuserid']
        };
        procedure.addDebitAccount(data, function(err, result) {    
            if (err) {
                response.render('openaccount', {error: "Something went wrong with the database"});
                console.log(err);
            }
            else {
                response.render('openaccount', {newaccount: "Account opened succesfully, ID " + accountID + "!"});
            }
        });
    });    
}

function addCreditAccountToCard() {

}

function a() {

}

/* Creates a 4-digit pin
*/
function randomizePin() {
    let pin = "";
    for (let i = 0; i < 4; i++) {
        pin = pin + Math.floor((Math.random() * 10));
    }
    return pin;
}

/* Loops through
*/
function findFreeAccountID(request, response, number, next) {
    account.getAccount(number, function(err, result) {
        if (err) {
            response.render('openaccount', {error: "Something went wrong with the database"});
            return;
        }
        // 0 rows returned means that there's no existing account with that ID
        else if (result.length == 0){
            let idString;
            if (number < 10) {
                idString = "0000" + number;
            }
            else if (number < 100) {
                idString = "000" + number;
            }
            else if (number < 1000) {
                idString = "00" + number;
            }
            else if (number < 10000) {
                idString = "0" + number;
            }
            else idString = "" + number;
            next(idString);
        }
        else {
            accountIDLoop(request, response, number, next);
        }
    });
}

function accountIDLoop(request, response, number, next) {
    let id = number + 1;
    findFreeAccountID(request, response, id, next);
}

function findFreeCardID(request, response, number, next) {
    let idString;
    if (no < 10) {
        idString = "060000000" + number;
    }
    else if (number < 100) {
        idString = "06000000" + number;
    }
    else if (number < 1000) {
        idString = "0600000" + number;
    }
    else if (number < 10000) {
        idString = "060000" + number;
    }
    else idString = "06000" + number;

    card.getCard(idString, function(err, result) {
        if (err) {
            next(false);
            return;
        }
        // 0 rows returned means that there's no existing account with that ID
        else if (result.length == 0){
            next(idString);
        }
        else {
            cardIDLoop(request, response, number, next);
        }
    });
}

function cardIDLoop(request, response, number, next) {
    let id = number + 1;
    findFreeCardID(request, response, id, next);
}

module.exports = {
    newServicesWindow,
    openDebitCard,
    openCreditCard,
    openAccount
}