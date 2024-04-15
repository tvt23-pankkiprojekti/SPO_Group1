const db=require('../database');
const bcrypt=require('bcryptjs');

const card={
    getCard(card, callback) {
        return db.query("SELECT id_card, state, owner, expiration, temp_restriction FROM card WHERE id_card = ?", [card], callback);
    }, //for admin

    getCardsByOwner(id_owner, callback) {
        return db.query("SELECT card.id_card, type, card.state AS state, expiration, temp_restriction FROM card INNER JOIN card_attached_account ON card.id_card = card_attached_account.id_card INNER JOIN account ON card_attached_account.id_account = account.id_account WHERE card.owner = ?", [id_owner], callback);
    },
    
    cardVerify(cVerify,  callback) {
        return db.query("SELECT state, temp_restriction, expiration FROM card WHERE id_card = ?", [cVerify], callback);
    }, //card verifying

    updateExpiration(card) {
        return db.query("UPDATE card SET state = 1 WHERE id_card = ?", [card]);
    }, // inserts an expiration notice onto a card's data

    login(uLogin, callback) {
        return db.query("SELECT pincode FROM card WHERE id_card = ?", [uLogin], callback);
    }, //verify correct pincode

    deleteCard(cDelete, callback) {
        return db.query("DELETE FROM card WHERE id_card = ?", [cDelete], callback);
    }, //delete selected card from database

    addCard(newCard, callback){
        bcrypt.hash(newCard.pincode,10,function(err,hashedPincode){
            return db.query("INSERT INTO card VALUES(?,?,?,?)",[newCard.id_card, newCard.id_owner, newCard.state, hashedPincode],callback);
        }); //add new card
    },
}

module.exports=card;
