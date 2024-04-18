const db=require('../database');
const bcrypt=require('bcryptjs');

const transaction={
    getTransactionHistory(id_account, callback) {
        return db.query("SELECT id_transaction, amount, time, description FROM transaction WHERE id_account = ? ORDER BY time DESC", [id_account], callback);
    }, //transaction history

    addTransaction(acc, am, des, callback) {
        return db.query("INSERT INTO transaction (id_account, amount, time, description) VALUES (?, ?, NOW(), ?)", [acc, am, des], callback);
    }, //add transaction to history

    getTransactionHistoryInRange(acc, start, end, callback) {
        return db.query("SELECT id_transaction, amount, time, description FROM transaction WHERE id_account = ? AND time BETWEEN ? AND ?  ORDER BY time DESC", [acc, start, end], callback);
    }, //gets transaction history within requested range

    depositToAccount(acc, am, callback) {
        return db.query("UPDATE account SET balance = balance + ? WHERE id_account = ?", [am, acc], callback);
    }, //update the account balance by adding the deposited amount

    withdrawFromAccount(acc, am, callback) {  
        return db.query("UPDATE account SET balance = balance - ? WHERE id_account = ?", [am, acc], callback);
    }, //update the account balance by subtracting the withdrawn amount
}

module.exports=transaction;