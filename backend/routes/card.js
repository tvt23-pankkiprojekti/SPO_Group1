var express = require('express');
var router = express.Router();
var card=require('../models/card_model');


router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

router.get('/:card',function(request,response){
    card.getCard(request.params.card, function(err,result){
        if(err){
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result[0]);
        }
    })
  });
  
  router.get('/:card',function(request,response){
    card.cardVerify(request.params.card, function(err,result){
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
  if(request.body.username && request.body.password){
      card.login(request.body.username, function(err,result){
          if(err){
              console.log(err.errno);
              response.json(err.errno);
          }
          else{
              if(result.length >0){
                  bcrypt.compare(request.body.password, result[0].password, function(err, compareResult){
                      if(compareResult){
                          console.log('Kirjautuminen ok');
                          const token=genToken({username: request.body.username});
                          response.send(token);
                      }
                      else {
                          console.log("Väärä salasana");
                          response.send(false);
                      }
                  })
              }
              else {
                  console.log("tunnusta ei ole");
                  response.send(false);
              }

          }
      });
  }
  else {
      console.log("Tunnus tai salasana puuttuu")
      response.send(false);
  }
});

function genToken(value){
  return jwt.sign(value, process.env.MY_TOKEN, {expiresIn: '200s'});
}
router.delete('/:card',function(request, response){
    card.deleteCard(request.params.card, function(err, result){
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
  
  router.post('/',function(request, response){
    card.addCard(request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
            //response.send(result[0].affectedRows)
        }
    });
  });

module.exports = router;