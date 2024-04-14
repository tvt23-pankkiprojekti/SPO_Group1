const user = require('../../models/user_model');
const account = require('../../models/account_model');
const card = require('../../models/card_model');
const token = require('jsonwebtoken');

const profile = {
  getData(request, response) {
    let userid = request.cookies['simulbankuserid'];

    if (!userid) {
      response.render('profile');
      return;
    }

    user.getUser(userid, function(err,result){
      if(err){
        response.render('profile', {error: true});
        return;
      };
      let userData = result[0];
      
      account.allAccountsByUser(userid, function(err,result){
        if(err){
          response.render('profile', {error: true});
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
            response.render('profile', {error: true});
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
          response.render('profile', {name: data['username'], id: data['id_user'], accounts: accounts, cards: cards});
        });
      });
    });
  }
}

module.exports=profile;