const db=require('../database');
const bcrypt=require('bcryptjs');

const accountOwnership={
    associateUserWithAccount(id_user, rights_level, id_account, callback) {
        return db.query("INSERT INTO account_ownership (id_user, rights_level, id_account) VALUES (?, ?, ?)", [id_user, rights_level, id_account], callback);
    }, //associate user with an account

    getUserAssociatedAccount(id_user, callback) {
        return db.query("SELECT id_account FROM account_ownership WHERE id_user = ?", [id_user], callback);
    }, //get the associated account of user

    removeAssociationUser(id_user, callback) {
        return db.query("DELETE FROM account_ownership WHERE id_user = ?", [id_user], callback);
    }, //remove association between user and an account
}

module.exports=accountOwnership;