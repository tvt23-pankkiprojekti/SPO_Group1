var user=require('../../models/user_model');
var account=require('../../models/account_model');
const token = require('jsonwebtoken');

const profile = {
  getData(request, response) {
    let userid = request.cookies['simulbankuserid'];
    let token = request.cookies['simulbanktoken'];

    if (!userid) {
      response.send("No user ID sent");
      return;
    }

    user.getUser(userid, function(err,result){
      if(err){
        response.send(err);
        return;
      };
      let userData = result[0];
      
      account.allAccountsByUser(userid, function(err,result){
        if(err){
          response.send(err);
          return;
        }
        let accountData = result[0];
        let data = {
          'username': userData['fname'] + " " + userData['lname'],
          'id_user': userid
        };

        let accounts = [];

        let i = 0;
        while (result[i] != null && result[i] != undefined) {
          console.log(result[i]);
          accounts.push(result[i]);
          i++;
        }
        response.render('profile', {name: data['username'], id: data['id_user'], accounts: accounts});
      });
    });
  }
}

module.exports=profile;