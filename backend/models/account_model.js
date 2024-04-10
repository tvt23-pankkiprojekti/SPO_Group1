const db=require('../database');
const bcrypt=require('bcryptjs');

const account={
    getAccount(getAcc, callback) {
    return db.query("SELECT * FROM account WHERE id_account = ?", [getAcc], callback);
    }, //for admins

    selectAccountType(selectAcc, callback) {
        return db.query("SELECT type FROM account WHERE id_account = ?", [selectAcc], callback);
    }, //select account at ATM

    getBalance(balance, callback) {
        return db.query("SELECT balance FROM account WHERE id_account = ?", [balance], callback);
    }, //shows the balance of selected account

    getLimit(limit, callback) {
        return db.query("SELECT credit_limit FROM account WHERE id_account = ?", [limit], callback);
    }, //shows the credit limit of selected account

    deleteAccount(deleteAcc, callback) {
        return db.query("DELETE FROM account WHERE id_account = ?", [deleteAcc], callback);
    }, //delete account

    addAccount(add, callback) {
        return db.query("INSERT INTO account (id_account, type, state, balance, owner, credit_limit) VALUES (?, ?, ?, ?, ?)", [acc, t, s, b, o, cl], callback);
    }, //add new account(

    allAccountsByUser(userid, callback){
        return db.query("SELECT id_account, balance FROM account WHERE owner=?", [userid], callback);
    },
}

module.exports=account;