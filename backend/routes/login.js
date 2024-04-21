const express = require('express');
const router = express.Router();
const card=require('../models/card_model');
const bcrypt = require('bcrypt');
const jwt = require('jsonwebtoken');

router.post('/',function(request, response){
    if(request.body.card && request.body.pincode){
        card.login(request.body.card, function(err,result){
            if(err){
                console.log(err.errno);
                response.json(err.errno);
            }
            else {
                if(result.length > 0){
                    bcrypt.hash(request.body.pincode, 10, function(err, hashedPin) {
                        if (err) {
                            console.log(err);
                            response.sendStatus(500);
                    } else {
                    bcrypt.compare(hashedPin, result[0].pincode, function(err, compareResult){
                        if(compareResult == true) {
                            console.log('Kirjautuminen onnistui');
                            const token = genToken({pincode: request.body.card});
                            response.json(token);
                        }
                    });
                }
                });
            }
                        else {
                            console.log("Väärä salasana");
                            response.send(false);
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
    return jwt.sign(value, process.env.Web_Token, {expiresIn: '200s'});
  }

  module.exports=router;
