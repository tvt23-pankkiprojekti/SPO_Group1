const db=require('../database');
const bcrypt=require('bcryptjs');

/* Creates:
    - a new credit account (curr. with a limit of €1000)
    - a new credit card
    - a card-account connection
    - a user-account connection
*/
function addCreditCardAndAccount(data, callback) {
    bcrypt.hash(data.pincode,10,function(err,hashedPincode){
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
    - a new debit card
    - a card-account connection
*/
function addDebitCard(data, callback) {
    bcrypt.hash(data.pincode,10,function(err,hashedPincode){
        return db.query("CALL openDebitCard(?, ?, ?, ?)", [data.id_card, data.id_account, data.id_user, hashedPincode], callback);
    });
}

module.exports = {
    addCreditCardAndAccount,
    addDebitAccount,
    addDebitCard
}