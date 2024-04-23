var express = require('express');
var router = express.Router();
var transaction = require('../models/transaction_model');

router.post('/', function(request, response) {
    /*if (!request.body.idaccount || isNaN(request.body.idaccount)) {
        response.send('Invalid parameters');
        return;
    }*/

    console.log("Token verified successfully");
    transaction.getTransactionHistory(request.body.idaccount, function(err, result) {
        if (err) {
            response.send(false);
            console.log(err);
        } else {
            console.log(result);
            response.send(result);
        }
    });
});

module.exports = router;