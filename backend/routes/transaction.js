var express = require('express');
var router = express.Router();
var transaction=require('../models/transaction_model');


router.get('/', function(request, response) {
  res.send('respond with a resource');
});

router.get('/:transaction',function(request,response){
  transaction.getTransHistory(request.params.transaction, function(err,result){
      if(err){
          response.send(err);
      }
      else{
          console.log(result);
          response.json(result[0]);
      }
  })
});

router.post('/withdraw',function(request,response){
  
  let message = "NOSTO "+ request.body.amount + "€";

  transaction.addTransaction(request.body.account, request.body.amount, message, function(err,result){
      if(err){
          response.send(err);
      }
      else{
          console.log(result);
          response.json(result[0]);
      }
  })
});

router.post('/insert',function(request,response){
  
  let message = "PANO"+ request.body.amount + "€";

  transaction.addTransaction(request.body.account, request.body.amount, message, function(err,result){
      if(err){
          response.send(err);
      }
      else{
          console.log(result);
          response.json(result[0]);
      }
  })
});


module.exports = router;