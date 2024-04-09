var express = require('express');
var router = express.Router();
var user = require('../models/user_model');


router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

router.get('/:user',function(request,response){
  user.getUser(request.params.user, function(err,result){
      if(err){
          response.send(err);
      }
      else{
          console.log(result);
          response.json(result[0]);
      }
  })
});

router.post('/',function(request, response){
  user.addUser(request.body, function(err, result){
      if(err){
          response.send(err);
      }
      else{
          response.json(result);
          //response.send(result[0].affectedRows)
      }
  });
});

router.put('/:user', function(request, response){
  user.updateUser(request.params.user, request.body, function(err, result){
      if(err){
          response.send(err);
      }
      else{
          //response.json(result);
          console.log(result.affectedRows);
          response.json(result.affectedRows);
      }
  });
});

router.delete('/:user',function(request, response){
  user.deleteUser(request.params.user, function(err, result){
      if(err){
          response.send(err);
      }
      else{
          //response.json(result);
          console.log(result.affectedRows);
          response.json(result.affectedRows);
      }
  });
});

module.exports = router;