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
                //console.log(result);
                let cards = [];
                let i = 0;
                while (result[i] != null && result[i] != undefined) {
                    // Converts the expiration to a yyyy-mm-dd from YYYY-MM-DDTHH:mm:ss.sssZ (or something of the like)
                    result[i]['expiration'] = new Date(result[i]['expiration']).toISOString().split('T')[0];
                    cards.push(result[i]);
                    i++;
                }

                next(false, cards, debitAccounts, creditAccounts, []);
			});
		});
    });
}

module.exports = {
    getUserData
}