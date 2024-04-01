const db=require('../database');
const bcrypt=require('bcryptjs');

const cardAttachedAccount={
    associateCardWithAccount(cardId, accountId, callback) {
        return db.query("INSERT INTO card_attached_account (card_id, account_id) VALUES (?, ?)", [cardId, accountId], callback);
    }, //associate a card with an account
    
    getAssociatedAccount(cardId, callback) {
        return db.query("SELECT account_id FROM card_attached_account WHERE card_id = ?", [cardId], callback);
    }, //get the associated account of a card

    removeAssociation(cardId, callback) {
        return db.query("DELETE FROM card_attached_account WHERE card_id = ?", [cardId], callback);
    }, //remove association between a card and an account
}