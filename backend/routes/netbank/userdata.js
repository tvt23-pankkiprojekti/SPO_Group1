const user = require('../../models/user_model');
const account = require('../../models/account_model');
const card = require('../../models/card_model');

function getUserData(request, response, next) {
    let userid = request.cookies['simulbankuserid'];

    if (!userid) {
        next(true, [], [], [], []);
        return;
    }

    account.allAccountsAccessibleByUser(userid, function(err,result){
        if(err){
            next(true, [], [], [], []);
            return;
        }

        let creditAccounts = [];
        let debitAccounts = [];
        let authorizedAccounts = [];
        let i = 0;
        while (result[i] != null && result[i] != undefined) {
            if (result[i]['state'] == null) {
                if (result[i]['rights_level'] != 1) {
                    authorizedAccounts.push(result[i])
                }
                else if (result[i]['type'] == 0) {
                    creditAccounts.push(result[i]);
                }
                else {
                    debitAccounts.push(result[i]);
                }
            }
            i++;
        }
        //console.log(creditAccounts);
        //console.log(debitAccounts);

        card.getCardsByOwner(userid, function(err, result) {
            if (err) {
                next(true, [], [], [], []);
                return;
            }
            //console.log(result);
            let cards = [];
            let i = 0;
            while (result[i] != null && result[i] != undefined) {
                // Converts the expiration to a yyyy-mm-dd from YYYY-MM-DDTHH:mm:ss.sssZ (or something of the like)
                result[i]['expiration'] = new Date(result[i]['expiration']).toISOString().split('T')[0];
                cards.push(result[i]);
                i++;
            }

            next(false, cards, debitAccounts, creditAccounts, authorizedAccounts);
        });
    });
}

function getCardApprovedAccounts(request, response, next) {
    let userid = request.cookies['simulbankuserid'];

    if (!userid) {
        next(true, [], [], [], []);
        return;
    }

    account.allAccountsAccessibleByUser(userid, function(err, accounts){
        if(err){
            next(true, [], [], [], []);
            return;
        }

        //console.log(creditAccounts);
        //console.log(debitAccounts);

        card.getCardsByOwner(userid, function(err, result) {
            if (err) {
                next(true, [], [], [], []);
                return;
            }
            //console.log(result);
            let cards = [];
            let i = 0;
            while (result[i] != null && result[i] != undefined) {
                // Converts the expiration to a yyyy-mm-dd from YYYY-MM-DDTHH:mm:ss.sssZ (or something of the like)
                result[i]['expiration'] = new Date(result[i]['expiration']).toISOString().split('T')[0];
                cards.push(result[i]);
                i++;
            }

            let creditAccounts = [];
            let debitAccounts = [];
            let authorizedAccounts = [];
            // Prunes out all accounts that already have a card attached (by the user)
            for (let j = 0; j < accounts.length; j++) {
                let accountCleared = true;
                for (let k = 0; k < cards.length; k++) {
                    if (accounts[j]['id_account'] == cards[k]['id_account']) {
                        //console.log(accounts[j]['id_account']);
                        //console.log(cards[k]['id_account']);
                        accountCleared = false;
                    }
                }
                // 'State' for things like frozen accounts
                if (accounts[j]['state'] == null && accountCleared == true) {
                    if (accounts[j]['rights_level'] != 1) {
                        //console.log(accounts[j]);
                        authorizedAccounts.push(accounts[i])
                    }
                    else if (accounts[j]['type'] == 0) {
                        creditAccounts.push(accounts[j]);
                    }
                    else {
                        debitAccounts.push(accounts[j]);
                    }
                }
            }

            // Sorts cards based on which have the option to attach a second account
            let debitAvailableCards = [];
            let creditAvailableCards = [];
            
            next(false, debitAvailableCards, creditAvailableCards, debitAccounts, creditAccounts, authorizedAccounts);
        });
    });
}

module.exports = {
    getUserData,
    getCardApprovedAccounts
}