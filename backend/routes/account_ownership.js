var express = require('express');
var router = express.Router();
var accountOwnership=require('../models/account_ownership_model');

router.get('/', function(req, res, next) {
    res.send('respond with a resource');
  });

router.get('/associate/:accountowner',function(request,response){
    accountOwnership.associateUserWithAccount(request.params.accountowner, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result[0]);
        }
    })
});

router.get('/user/:accountowner',function(request,response){
    accountOwnership.getUserAssociatedAccount(request.params.accountowner, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result[0]);
        }
    })
});

router.delete('/:accountowner',function(request, response){
    accountOwnership.removeAssociationUser(request.params.accountowner, function(err, result){
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

module.exports = router;