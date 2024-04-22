const user = require('../../models/user_model');
const account = require('../../models/account_model');
const card = require('../../models/card_model');

function getUserData(request, response, next) {
    let userid = request.cookies['simulbankuserid'];

    if (!userid) {
        next(true, [], [], [], []);
        return;
    }

    user.getUser(userid, function(err,result){
		if(err){
			next(true, [], [], [], []);
			return;
		};
		let userData = result[0];

		account.allAccountsAccessibleByUser(userid, function(err,result){
			if(err){
				next(true, [], [], [], []);
				return;
			}

			let creditAccounts = [];
            let debitAccounts = [];
			let i = 0;
			while (result[i] != null && result[i] != undefined) {
                if (result[i]['state'] == null) {
                    if (result[i]['type'] == 0) {
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
                // 'State' for things like frozen accounts
                if (accounts[j]['state'] == null && accountCleared == true) {
                    // rights_level 1 for personally owned accounts
                    if (accounts[j]['rights_level'] != 1) {
                        //console.log(accounts[j]);
                        authorizedAccounts.push(accounts[j])
                    }
                    // Type 0 for credit
                    else if (accounts[j]['type'] == 0) {
                        creditAccounts.push(accounts[j]);
                    }
                    else {
                        debitAccounts.push(accounts[j]);
                    }
                }
            }

                next(false, cards, debitAccounts, creditAccounts, []);
			});
		});
    });
}

module.exports = {
    getUserData,
    getCardApprovedAccounts
}