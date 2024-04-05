const db=require('../database');
const bcrypt=require('bcryptjs');

const transaction={
    getTransactionHistory(history, callback) {
        return db.query("SELECT id_transaction, amount, time, description FROM transaction WHERE id_account = ?", [history], callback);
    }, //transaction history

    addTransaction(acc, am, des, callback) {
        return db.query("INSERT INTO transaction (id_account, amount, time, description) VALUES (?, ?, NOW(), ?)", [acc, am, des], callback);
    }, //add transaction to history

    getTransactionHistoryInRange(accountId, start, end, callback) {
        return db.query("SELECT id_transaction, amount, time, description FROM transaction WHERE id_account = ? AND id_transaction BETWEEN ? AND ?", [accountId, start, end], callback);
    }, //gets transaction history within requested range

    depositToAccount(acc, am, callback) {
        return db.query("UPDATE account SET balance = balance + ? WHERE id_account = ?", [am, acc], callback);
    }, //update the account balance by adding the deposited amount

    withdrawFromAccount(acc, am, callback) {  
        return db.query("UPDATE account SET balance = balance - ? WHERE id_account = ?", [am, acc], callback);
    }, //update the account balance by subtracting the withdrawn amount
}

module.exports=transaction;