var express = require('express');
var router = express.Router();
var transaction = require('../models/transaction_model');


router.post('/', function(request, response) {
    /*if (!request.body.idaccount || isNaN(request.body.idaccount)) {
        response.send('Invalid parameters');
        return;
    }*/

    transaction.getTransactionHistory(request.body.idaccount, function(err, result) {
        if (err) {
            response.send(err);
            console.log(error);
        } else {
            //console.log(result);
            response.send(result);
        }
    });
});

module.exports = router;