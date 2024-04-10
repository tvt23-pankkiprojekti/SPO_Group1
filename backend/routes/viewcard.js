// Ehkä tässä olisikin pitänyt olla 



var express = require('express');
var router = express.Router();
var user=require('../models/user_model');
var account=require('../models/account_model');


router.get('/', function(request, response) {
  let answer = [];

  user.getUser(request.body.user, function(err,result){
  if(err){
    response.send(err);
    return;
  }
  else{
    answer.push(result);
    console.log(result);
  } 
  
  account.allAccountsByUser(request.body.user, function(err,result){
    if(err){
      response.send(err);
      return;
    }
    else{
      answer.push(result);
      console.log(result);
    }  
    response.send(answer);

    /* transaction.getTransHistory(request.body.user, function(err,result){
      if(err){
        answer.push(err);
      }
      else{
        answer.push(result);
        console.log(result);
      } 
      response.send(answer);
      })*/
    });
  });
});

module.exports=router;
