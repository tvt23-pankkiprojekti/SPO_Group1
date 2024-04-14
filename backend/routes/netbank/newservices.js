const express = require('express');
const router = express.Router();
const user = require('../../models/user_model');

const services = {
    newServicesWindow(request, response) {
        let userid = request.cookies['simulbankuserid'];

        user.getAccountAndCardData(userid, function(err, result) {
            if (err) {
                response.render('newservices', {error: "Database error"});
                return;
            }
            let accounts = [];
            let cards = [];
            let i = 0;

            while (result[i] != null && result[i] != undefined) {
                if (result[i]['description'] == "accounts") {
                    accounts.push(result[i]['data']);
                }
                else {
                    cards.push(result[i]['data']);
                }
                i++;
            }
            console.log("Accounts: ");
            console.log(accounts);
            console.log("Cards: ");
            console.log(cards);
            response.render('newservices', {accounts: accounts, cards: cards});
        });
    }
}

module.exports = services;