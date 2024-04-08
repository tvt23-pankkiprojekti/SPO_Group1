var express = require('express');
var router = express.Router();
var transaction = require('../models/transaction_model');


router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

router.get('/:viewtransactions', function(request, response) {
    if (!request.query.start || !request.query.end || isNaN(request.query.start) || isNaN(request.query.end)) {
      response.send("Invalid parameters");
      return;
    }

    function getTransactionHistoryLoop(viewtransactions, start, end, callback) {
      transaction.getTransactionHistoryInRange(viewtransactions, start, end, function(err, result) {
          if (err) {
              callback(err);
          } else {
              console.log(result);
              response.json(result);

              if (result.length > 0) {
                  const lastTransactionDate = result[result.length - 1].date;
                  getTransactionHistoryLoop(viewtransactions, start, lastTransactionDate, callback);
              } else {
                  callback(null, "All transactions fetched");
              }
          }
      });
  }

  getTransactionHistoryLoop(request.params.viewtransactions, request.query.start, request.query.end, function(err, result) {
    if (err) {
      response.send(result);
    } else {
      console.log(result);
      response.send(result);
    }
});
});


module.exports = router;
