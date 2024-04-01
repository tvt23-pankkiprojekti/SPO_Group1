var express = require('express');
var router = express.Router();
var transaction=require('../models/transaction_model');


router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

router.get('/:transac',function(request,response){
  transaction.getTransHistory(request.params.transac, function(err,result){
      if(err){
          response.send(err);
      }
      else{
          console.log(result);
          response.json(result[0]);
      }
  })
});

router.post('/',function(request,response){
  transaction.addTransaction(request.body, function(err,result){
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