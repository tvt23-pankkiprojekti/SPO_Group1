const db=require('../database');
const bcrypt=require('bcryptjs');

const cardAttachedAccount={
    associateCardWithAccount(cardId, accountId, callback) {
        return db.query("INSERT INTO card_attached_account (id_card, id_account) VALUES (?, ?)", [cardId, accountId], callback);
    }, //associate a card with an account
    
    getCardAssociatedAccount(cardId, callback) {
        return db.query("SELECT id_account FROM card_attached_account WHERE id_card = ?", [cardId], callback);
    }, //get the associated account of a card

    removeAssociationCard(cardId, callback) {
        return db.query("DELETE FROM card_attached_account WHERE id_card = ?", [cardId], callback);
    }, //remove association between a card and an account
}

module.exports=cardAttachedAccount;