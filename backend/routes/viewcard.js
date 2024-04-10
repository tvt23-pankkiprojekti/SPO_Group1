// Ehkä tässä olisikin pitänyt olla 



var express = require('express');
var router = express.Router();
var user=require('../models/user_model');
var accountAttached=require('../models/card_attached_account_model');
var card=require('../models/card_model');
var account=require('../models/account_model');
var transaction=require('../models/transaction_model');

router.get('/', function(request, response) {
  let answer = [];
  console.log(request.body.card)

  card.getCard(request.body.card, function(err,result){
  if(err){
    response.send(err);
    return;
  }
  let cardData = result[0];
  console.log(cardData);

    user.getUser(cardData.owner, function(err,result){
      if(err){
        response.send(err);
        return;
      }
      let cardOwnerData = result[0];
    
      accountAttached.getCardAssociatedAccount(cardData.id_card, function(err,result){
        if(err){
          response.send(err);
          return;
        }
        let accountId = result[0];

        account.getAccount(accountId.id_account, function(err,result){
          if(err){
            response.send(err);
            return;
          }
          let accountData = result[0];

          user.getUser(accountData.owner, function(err,result){
            if(err){
              response.send(err);
              return;
            }
            let userData = result[0];

            transaction.getTransactionHistory(accountData.id_account, function(err,result){
              if(err){
                answer.push(err);
              }

              let answer =[ {
                "id_card": cardData.id_account,
                "id_card_owner": cardData.owner,
                "card_owner": cardOwnerData.fname+" "+cardOwnerData.lname,
                "id_account": accountData.id_account,
                "id_account_owner": userData.id_user,
                "account_owner": userData.fname+" "+userData.lname 
              },
                result[0], 
                result[1], 
                result[2], 
                result[3], 
                result[4]
              ];
              response.send(answer);
            });
          });
        });
      });
    });
  });
});

module.exports=router;
