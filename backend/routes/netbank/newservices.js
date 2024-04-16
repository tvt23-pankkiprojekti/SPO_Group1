const user = require('../../models/user_model');
const account = require('../../models/account_model');
const accountOwnership = require('../../models/account_ownership_model');
const card = require('../../models/card_model');
const cardOwnership = require('../../models/card_attached_account_model');
const userdata = require('./userdata');

function newServicesWindow(request, response) {
    userdata.getUserData(request, response, function(user, cards, accounts) {
        response.render('newservices', {accounts: accounts, cards: cards});
    });
}

function openDebitCard(request, response) {

}

function openCreditCard(request, response) {
    openAccount(request, response, 0, function(request, response, accountID) {
        findFreeCardID(request, response, 0, function(cardID) {
            if (cardID == false) {
                response.render('getcard', {error: "Database error with finding ID"});
                return;
            }
            else {
                let pin = randomizePin();
                createCard(request, response, cardID, pin, function(result) {
                    if (result == false) {
                        response.render('getcard', {error: "Database error with creating card"});
                        return;
                    }
                    else {
                        bindCard(request, response, cardID, accountID, function(result) {
                            if (result == false) {
                                response.render('getcard', {error: "Database error with binding card to account"});
                                return;
                            }
                            else {
                                cardCreated(request, response, cardID, pin);
                            }
                        });
                    }
                });
            }
        })
    });
}

function randomizePin() {
    let pin = "";
    for (let i = 0; i < 3; i++) {
        pin = pin + Math.floor((Math.random() * 10));
    }
    return pin;
}

function createCard(request, response, cardID, pin, next) {
    let newCard = {
        id_card: cardID,
        id_owner: request.cookies['simulbankuserid'],
        state: null,
        pincode: pin
    }
    card.addCard(newCard, function(err, result) {
        if (err) {
            console.log(err);
            next(false);
        }
        else {
            next();
        }
    });
}

function bindCard(request, response, cardID, accountID, next) {
    cardOwnership.associateCardWithAccount(cardID, accountID, function(err, result) {
        if (err) {
            console.log(err);
            next(false);
        }
        else {
            next();
        }
    });
}

function openAccount(request, response, accountType, next) {
    findFreeAccountID(request, response, 0, function(idString) {
        account.addAccount(idString, accountType, null, 0.00, request.cookies['simulbankuserid'], (accountType == 1) ? 0.00 : 5000.00, function(err, result) {
            if (err) {
                response.render('openaccount', {error: "Something went wrong with the database"});
            }
            else {
                next(request, response, idString);
            }
        });
    });    
}

function findFreeAccountID(request, response, no, next) {
    let id = no;

    account.getAccount(id, function(err, result) {
        if (err) {
            response.render('openaccount', {error: "Something went wrong with the database"});
            return;
        }
        // 0 rows returned means that there's no existing account with that ID
        else if (result.length == 0){
            let idString;
            if (id < 10) {
                idString = "0000" + id;
            }
            else if (id < 100) {
                idString = "000" + id;
            }
            else if (id < 1000) {
                idString = "00" + id;
            }
            else if (id < 10000) {
                idString = "0" + id;
            }
            else idString = "" + id;
            next(idString);
        }
        else {
            accountIDLoop(request, response, id, next);
        }
    });
}

function accountIDLoop(request, response, no, next) {
    let id = no + 1;
    findFreeAccountID(request, response, id, next);
}

function findFreeCardID(request, response, no, next) {
    let idString;
    if (no < 10) {
        idString = "060000000" + no;
    }
    else if (no < 100) {
        idString = "06000000" + no;
    }
    else if (no < 1000) {
        idString = "0600000" + no;
    }
    else if (no < 10000) {
        idString = "060000" + no;
    }
    else idString = "06000" + no;

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
            cardIDLoop(request, response, no, next);
        }
    });
}

function cardIDLoop(request, response, no, next) {
    let id = no + 1;
    findFreeCardID(request, response, id, next);
}

function debitAccountOpened(request, response, accountID) {
    response.render('openaccount', {newaccount: "Account opened succesfully, ID " + accountID + "!"});
}

function cardCreated(request, response, cardID, pin) {
    response.render('getcard', {newcard: "Your credit card was succesfully created: ID " + cardID + ", PIN " + pin + "." });
}

module.exports = {
    newServicesWindow,
    openDebitCard,
    openCreditCard,
    openAccount
}