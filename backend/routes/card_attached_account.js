var express = require('express');
var router = express.Router();
var cardAttachedAccount=require('../models/card_attached_account_model');

router.get('/', function(req, res, next) {
    res.send('respond with a resource');
  });

router.get('/associate/:cardattached',function(request,response){
    cardAttachedAccount.associateCardWithAccount(request.params.cardattached, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result[0]);
        }
    })
});

router.get('/card/:cardattached',function(request,response){
    cardAttachedAccount.getCardAssociatedAccount(request.params.cardattached, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result[0]);
        }
    })
});

router.delete('/:cardattached',function(request, response){
    cardAttachedAccount.removeAssociationCard(request.params.cardattached, function(err, result){
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