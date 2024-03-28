const db=require('../database');
const bcrypt=require('bcryptjs');

const account={
    getAccount(acc, callback) {
    return db.query("SELECT * FROM account WHERE owner = ?", [acc], callback);
    }, //for admins

    selectAccount(sa, callback) {
        return db.query("SELECT type FROM account WHERE owner = ?", [sa], callback);
    }, //select account at ATM

    getBalance(ba, callback) {
        return db.query("SELECT balance FROM account WHERE owner = ?", [ba], callback);
    }, //shows the balance of selected account

    getLimit(lim, callback) {
        return db.query("SELECT credit_limit FROM account WHERE owner = ?", [lim], callback);
    }, //shows the credit limit of selected account

    deleteAccount(acc, callback) {
        return db.query("DELETE FROM account WHERE id_account = ?", [acc], callback);
    }, //delete account

    addAccount(acc, t, s, b, o, cl, callback) {
        return db.query("INSERT INTO account (id_account, type, state, balance, owner, credit_limit) VALUES (?, ?, ?, ?, ?)", [acc, t, s, b, o, cl,], callback);
    }, //add new account
}