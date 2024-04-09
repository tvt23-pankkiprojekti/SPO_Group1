var express = require('express');
var router = express.Router();
var transaction = require('../models/transaction_model');


router.get('/', function(request, response) {
    /*if (!request.body.start || !request.body.end || !request.body.idaccount || isNaN(request.body.start) || isNaN(request.body.end) || isNaN(request.body.idaccount)) {
      response.send('Invalid parameters');
      return;
    }*/

      transaction.getTransactionHistoryInRange(request.body.idaccount, request.body.start, request.body.end, function(err, result) {
          if (err) {
              callback(err);
          } else {
              console.log(result);

              if (result.length > 0) {
                  let lastTransactionDate = result[result.length - 1].date;
                  console.log(lastTransactionDate);
                  response.send(result);
              } else {
                  callback(null, 'All transactions fetched');
              }
          }
      });
});


module.exports = router;
