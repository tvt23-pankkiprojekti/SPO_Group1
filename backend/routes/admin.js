var express = require('express');
var router = express.Router();
var admin=require('../models/admin_model');


router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

router.get('/:admin',function(request,response){
    card.adminLogin(request.params.admin, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result[0]);
        }
    })
});

router.get('/:admin',function(request,response){
    card.adminVerify(request.params.admin, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result[0]);
        }
    })
});

router.get('/:admin',function(request,response){
    card.checkRights(request.params.admin, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result[0]);
        }
    })
});

module.exports = router;