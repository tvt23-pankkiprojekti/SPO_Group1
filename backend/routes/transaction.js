var express = require('express');
var router = express.Router();
var transaction = require('../models/transaction_model');
const tokenCheck = require('./verifytoken');

router.get('/transaction',function(request,response){

    tokenCheck.verify(request, response, function(err, request, response) {
        if (err) {
            console.log(err);
            response.send(false);
        }
        else {
    transaction.getTransactionHistory(request.params.transaction, function(err, result){
        if(err) {
          response.send(err);
        }
        else {
          console.log(result);
          response.json(result[0]);
        }
    });
}
});
});

router.post('/withdraw',function(request, response){
    
    let message = "NOSTO "+ request.body.amount + "€";

    tokenCheck.verify(request, response, function(err, request, response) {
        if (err) {
            console.log(err);
            response.send(false);
        }
        else {
    transaction.addTransaction(request.body.account, request.body.amount, message, function(err, result){
        if(err){
            response.send(err);
        }
        else {
            console.log(result);
            response.json(result[0]);
        }
    });
}
});
});

router.post('/deposit',function(request, response){
  
    let message = "PANO"+ request.body.amount + "€";

    tokenCheck.verify(request, response, function(err, request, response) {
        if (err) {
            console.log(err);
            response.send(false);
        }
        else {
    transaction.addTransaction(request.body.account, request.body.amount, message, function(err, result){
        if(err) {
            response.send(err);
        }
        else {
            console.log(result);
            response.json(result[0]);
        }
    });
}
});
});

router.post('/addtobalance', function(request, response) {
    
    tokenCheck.verify(request, response, function(err, request, response) {
        if (err) {
            console.log(err);
            response.send(false);
        }
        else {
    transaction.addTransaction(request.body.account, request.body.amount,function(err, result) {
        if (err) {
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result[0]);
        }

        transaction.depositToAccount(request.body.account, request.body.amount, function(err, result) {
            if (err) {
                response.send(err);
            }
            else{
                console.log(result);
                response.json(result[0]);
            }
        });
    });
}
});
});


router.post('/withdrawfrombalance', function(request, response) {
    
    tokenCheck.verify(request, response, function(err, request, response) {
        if (err) {
            console.log(err);
            response.send(false);
        }
        else {
    transaction.addTransaction(request.body.account, request.body.amount, function(err, result) {
        if (err) {
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result[0]);
        }

        transaction.withdrawFromAccount(request.body.account, request.body.amount, function(err, result) {
            if (err) {
                response.send(err);
            }
            else{
                console.log(result);
                response.json(result[0]);
            }
        });
    });
}
});
});


module.exports = router;