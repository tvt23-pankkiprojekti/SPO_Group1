var express = require('express');
var router = express.Router();
var transaction=require('../models/transaction_model');


router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

module.exports = router;