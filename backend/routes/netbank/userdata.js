const user = require('../../models/user_model');
const account = require('../../models/account_model');
const card = require('../../models/card_model');

function getUserData(request, response, next) {
    let userid = request.cookies['simulbankuserid'];

    if (!userid) {
        next(true, [], [], []);
        return;
    }

    user.getUser(userid, function(err,result){
		if(err){
			next(true, [], [], []);
			return;
		};
		let userData = result[0];

		account.allAccountsByUser(userid, function(err,result){
			if(err){
				next(true, [], [], []);
				return;
			}

			let accounts = [];
			let i = 0;
			while (result[i] != null && result[i] != undefined) {
                //console.log(result[i]);
                accounts.push(result[i]);
                i++;
			}

			card.getCardsByOwner(userid, function(err, result) {
                if (err) {
                    next(true, [], [], []);
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

                let data = {
                'username': userData['fname'] + " " + userData['lname'],
                'id_user': userid
                };

                next(false, data, cards, accounts);
			});
		});
    });
}

module.exports = {
    getUserData
}