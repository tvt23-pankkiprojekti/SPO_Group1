var express = require('express');
var router = express.Router();
var transaction=require('../models/transaction_model');


router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

router.get('/:viewtransactions', function(request, response) {
    if (!request.query.start || !request.query.end || isNaN(request.query.start) || isNaN(request.query.end)) {
      response.send(err);
    }

    transaction.getTransHistoryInRange(request.params.viewtransactions, request.query.start, request.query.end, function(err, result) {
      if (err) {
        response.send(err);

      } else {
        console.log(result);
        response.json(result);
      }
    });
});


module.exports = router;
