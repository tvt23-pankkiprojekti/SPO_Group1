const db=require('../database');
const bcrypt=require('bcryptjs');

const accountOwnership={
    associateUserWithAccount(userId, accountId, callback) {
        return db.query("INSERT INTO account_ownership (id_user, id_account) VALUES (?, ?)", [userId, accountId], callback);
    }, //associate user with an account

    getUserAssociatedAccount(userId, callback) {
        return db.query("SELECT id_account FROM account_ownership WHERE id_user = ?", [userId], callback);
    }, //get the associated account of user

    removeAssociationUser(userId, callback) {
        return db.query("DELETE FROM account_ownership WHERE id_user = ?", [userId], callback);
    }, //remove association between user and an account
}

module.exports=accountOwnership;