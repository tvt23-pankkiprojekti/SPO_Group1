const db=require('../database');
const bcrypt=require('bcryptjs');


const card={
    getCard(c, callback) {
        return db.query("SELECT id_card, state, owner, expiration, temp_restriction FROM card WHERE id_card = ?",[c], callback);
    }, //for admins
    
    cardVerify(cv,  callback) {
        return db.query("SELECT state, temp_restriction, expiration FROM card WHERE id_card = ?", [cv], callback);
    }, //card verifying

    login(lg, callback) {
        return db.query("SELECT pincode FROM card WHERE id_card = ?", [lg], callback);
    }, //verify correct pincode

    deleteCard(dc, callback) {
        return db.query("DELETE FROM card WHERE id_card = ?", [dc], callback);
    }, //delete selected card from database

    addCard(c, s, o, e, t, callback) {
        return db.query("INSERT INTO card (id_card, state, owner, expiration, temp_restriction) VALUES (?, ?, ?, ?, ?)", [c, s, o, e, t], callback);
    }, //add new card
}

module.exports=card;