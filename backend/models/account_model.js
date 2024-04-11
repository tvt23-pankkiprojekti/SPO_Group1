const db=require('../database');
const bcrypt=require('bcryptjs');

const account={
    getAccount(id_account, callback) {
    return db.query("SELECT * FROM account WHERE id_account = ?", [id_account], callback);
    }, //for admins

    selectAccountType(id_account, callback) {
        return db.query("SELECT type FROM account WHERE id_account = ?", [id_account], callback);
    }, //select account at ATM

    getBalance(id_account, callback) {
        return db.query("SELECT balance FROM account WHERE id_account = ?", [id_account], callback);
    }, //shows the balance of selected account

    getLimit(id_account, callback) {
        return db.query("SELECT credit_limit FROM account WHERE id_account = ?", [id_account], callback);
    }, //shows the credit limit of selected account

    deleteAccount(id_account, callback) {
        return db.query("DELETE FROM account WHERE id_account = ?", [id_account], callback);
    }, //delete account

    addAccount(acc, type, state, balance, owner, credit, callback) {
        return db.query("INSERT INTO account (id_account, type, state, balance, owner, credit_limit) VALUES (?, ?, ?, ?, ?)", [acc, type, state, balance, owner, credit], callback);
    }, //add new account(

    allAccountsByUser(id_account, callback){
        return db.query("SELECT id_account, balance FROM account WHERE owner=?", [id_account], callback);
    },
}

module.exports=account;