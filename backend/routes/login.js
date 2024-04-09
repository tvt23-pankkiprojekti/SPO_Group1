var express = require('express');
var router = express.Router();
var card=require('../models/card_model');


router.post('/',function(request, response){
    if(request.body.card && request.body.pincode){
        card.login(request.body.card, function(err,result){
            if(err){
                console.log(err.errno);
                response.json(err.errno);
            }
            else{
                if(result.length >0){
                    bcrypt.compare(request.body.pincode, result[0].pincode, function(err, compareResult){
                        if(compareResult){
                            console.log('Kirjautuminen onnistui');
                            const token=genToken({pincode: request.body.pincode});
                            response.send(token);
                        }
                        else {
                            console.log("Väärä salasana");
                            response.send(false);
                        }
                    })
                }
  
            }
        });
    }

    else {
        console.log("Tieto puuttuu")
        response.send(false);
    }
  });
  
  function genToken(value){
    return jwt.sign(value, process.env.MY_TOKEN, {expiresIn: '200s'});
  }

  module.exports=router;
