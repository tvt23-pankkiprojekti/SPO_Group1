const db=require('../database');
const bcrypt=require('bcryptjs');

const account={
    getAccount(acc, callback){
    return db.query("SELECT * FROM account WHERE owner = ?", [acc], callback); // for admins

    }, 

    selectAccount(sa, callback){
        return db.query("SELECT type FROM account WHERE owner = ?", [sa], callback);//select account at ATM
    },

    getBalance(ba, callback){
        retrun db.query("SELECT balance FROM account WHERE owner = ?", [ba], callback);//shows the balance of selected account
    },

    getLimit(lim, callback){
        retrun db.query("SELECT credit_limit FROM account WHERE owner = ?", [lim], callback);//shows the credit limit of selected account
    }



