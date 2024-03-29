var express = require('express');
var router = express.Router();
var account=require('../models/account_model');


router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

router.get('/:usern',function(request,response){
  account.getAccount(request.params.usern, function(err,result){
      if(err){
          response.send(err);
      }
      else{
          console.log(result);
          response.json(result[0]);
      }
  })
});

router.get('/:usern',function(request,response){
  account.selectAccount(request.params.usern, function(err,result){
      if(err){
          response.send(err);
      }
      else{
          console.log(result);
          response.json(result[0]);
      }
  })
});

router.get('/:usern',function(request,response){
  account.getBalance(request.params.usern, function(err,result){
      if(err){
          response.send(err);
      }
      else{
          console.log(result);
          response.json(result[0]);
      }
  })
});

router.get('/:usern',function(request,response){
  account.getLimit(request.params.usern, function(err,result){
      if(err){
          response.send(err);
      }
      else{
          console.log(result);
          response.json(result[0]);
      }
  })
});

router.delete('/:usern',function(request, response){
  account.deleteAccount(request.params.usern, function(err, result){
      if(err){
          response.send(err);
      }
      else{
          //response.json(result);
          console.log(result.affectedRows);
          response.json(result.affectedRows);
      }
  });
});

router.post('/',function(request, response){
  account.addAccount(request.body, function(err, result){
      if(err){
          response.send(err);
      }
      else{
          response.json(result);
          //response.send(result[0].affectedRows)
      }
  });
});

module.exports = router;