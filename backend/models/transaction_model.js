const db=require('../database');
const bcrypt=require('bcryptjs');

const transaction={
    getTransHistory(acc, callback) {
        return db.query("SELECT id_transaction, amount, time, description FROM transaction WHERE id_account = ?", [acc], callback);
    }, //transaction history

    addTransaction(acc, am, des, callback) {
        return db.query("INSERT INTO transaction (id_account, amount, time, description) VALUES (?, ?, NOW(), ?)", [acc, am, des], callback);
    }, //add transaction to history    
    
    /* getAccountBalance: "SELECT SUM(amount) AS balance FROM transaction WHERE id_account = ?"
        This would calculate and return the current balance of an account based on its transaction history */
}

module.exports=transaction;