const db=require('../database');
const bcrypt=require('bcryptjs');

const accountOwnership={
    associateUserWithAccount(user, acc, callback) {
        return db.query("INSERT INTO account_ownership (id_user, id_account) VALUES (?, ?)", [user, acc], callback);
    }, //associate user with an account

    getUserAssociatedAccount(user, callback) {
        return db.query("SELECT id_account FROM account_ownership WHERE id_user = ?", [user], callback);
    }, //get the associated account of user

    removeAssociationUser(user, callback) {
        return db.query("DELETE FROM account_ownership WHERE id_user = ?", [user], callback);
    }, //remove association between user and an account
}

module.exports=accountOwnership;