var express = require('express');
var router = express.Router();
var transaction = require('../models/transaction_model');
var transaction = require('../models/account_model');
const tokenCheck = require('./verifytoken');
const { token } = require('morgan');

router.post('/', function(request, response) {
    console.log("Request for account balance for user with card " + request.body['card']);

    tokenCheck.verify(request, request.body['card'], function(err) {
        if (err) {
            console.log(err);
            response.send(false);
        } else {
            account.getAccount(request.body['account'], function(err, accountResult) {
                if (err) {
                    response.send(err);
                    return;
                } else if (!accountResult[0]) {
                    response.send(false);
                    return;
                }

                let accountId = accountResult[0].id_account;
                transaction.getBalance(accountId, function(err, accountBalance) {
                    if (err) {
                        response.send(false);
                        return;
                    }

                    response.send(accountBalance);
                });
            });
        }
    });
});


router.get('/transaction',function(request,response){

    tokenCheck.verify(request, response, function(err) {
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

    tokenCheck.verify(request, response, function(err) {
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

    tokenCheck.verify(request, response, function(err) {
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
    
    tokenCheck.verify(request, response, function(err) {
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
    
    tokenCheck.verify(request, response, function(err) {
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