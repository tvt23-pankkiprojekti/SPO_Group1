var express = require('express');
var router = express.Router();
var user = require("../models/user_model");

/* GET users listing. */
router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

router.get('/:userno',function(request,response){
  user.getUser(request.params.userno, function(err,result){
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
  student.addUser(request.body, function(err, result){
      if(err){
          response.send(err);
      }
      else{
          response.json(result);
          //response.send(result[0].affectedRows)
      }
  });
});

router.put('/:usern', function(request, response){
  student.updateUser(request.params.usern, request.body, function(err, result){
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

router.delete('/:usern',function(request, response){
  student.deleteUser(request.params.usern, function(err, result){
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
