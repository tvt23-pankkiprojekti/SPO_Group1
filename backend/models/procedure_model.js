const db=require('../database');
const bcrypt=require('bcryptjs');

/* Most of these are procedures because they require multiple steps and it's easier to catch errors
with SQL TRANSACTION.
*/

/* Creates:
    - a new credit account (curr. with a limit of €1000)
    - a new credit card
    - a card-account connection
    - a user-account connection
*/
function addCreditCardAndAccount(data, callback) {
    bcrypt.hash(data.pincode, 10, function(err, hashedPincode) {
        return db.query("CALL openCreditCard(?, ?, ?, ?, ?)", [data.id_card, data.id_user, hashedPincode, data.id_account, data.credit_limit], callback);
    });
}

/* Creates:
    - a new debit account
    - a user-account connection
*/
function addDebitAccount(data, callback) {
    return db.query("CALL openDebitAccount(?, ?)", [data.id_account, data.id_user], callback);
}

/* Creates:
    - a new card
    - a card-account connection
*/
function addNewCard(data, callback) {
    bcrypt.hash(data.pincode, 10, function(err, hashedPincode) {
        return db.query("CALL openNewCard(?, ?, ?, ?)", [data.id_card, data.id_account, data.id_user, hashedPincode], callback);
    });
}

/* Creates:
    - a new card
    - a card-account connection
    - a user-account connection
*/
function addAuthorizedCard(data, callback) {
    bcrypt.hash(data.pincode, 10, function(err, hashedPincode) {
        return db.query("CALL addAuthorizedCard(?, ?, ?, ?, ?)", [data.id_card, data.id_user, hashedPincode, data.id_account, data.credit_limit], callback);
    });
}

/*  Does:
    - deduct the amount from account one
    - add the amount to account two
    - create a transaction record with account one, amount, current time and a description
*/
function accountToAccountTransaction(data, callback) {
    return db.query("CALL accountToAccountTransaction(?, ?, ?, ?)", [data.account_one, data.account_two, data.amount, data.description], callback);
}

module.exports = {
    addCreditCardAndAccount,
    addDebitAccount,
    addNewCard,
    addAuthorizedCard,
    accountToAccountTransaction
}