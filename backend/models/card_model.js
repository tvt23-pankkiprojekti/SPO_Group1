const db=require('../database');
const bcrypt=require('bcryptjs');


const card={
    getCard(c, callback){
        return db.query("SELECT id_card, state, owner, expiration, temp_restriction FROM card WHERE id_card = ?",[c], callback);
    }, // for admins
    
    cardVerify(cv,  callback){
        return db.query("SELECT state, temp_restriction, expiration FROM card WHERE id_card = ?", [cv], callback);
    }, //card verifying

    login(lg, callback){
        return db.query("SELECT pincode FROM card WHERE id_card = ?", [lg], callback);
    } //verify correct pincode


}