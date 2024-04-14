var express = require('express');
var router = express.Router();
var admin = require('../models/admin_model');
var account = require('../models/account_model');
var accountOwnership = require('../models/account_ownership_model');
var card = require('../models/card_model');
var cardAccount = require('../models/card_attached_account_model');
var transaction = require('../models/transaction_model');
var user = require('../models/user_model');


router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

router.post('/login',function(request, response){
    admin.adminLogin(request.body.id_admin, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result[0]);
        }
    })
});

router.get('/home',function(request, response){
    admin.adminVerify(request.params.admin, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result[0]);
        }
    })
});

/*function checkAdminRights(request, response, next) {
    admin.checkRights(request.params.admin, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result[0]);
        }
    })
    next(request, response, )
}*/

module.exports = router;