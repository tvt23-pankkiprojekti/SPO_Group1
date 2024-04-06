const express = require('express');
const router = express.Router();
const card = require('../models/card_model');

/* {{url}}/bankomat/verifycard, kutsutaan kun halutaan tarkistaa onko maattiin syötetty kortti
pankin listoilla & käytettävissä, mukaan laitetaan kortin numero
*/
router.post('/', function(request, response) {
    if (!request.body['cardno']) {
        response.send("Ei kortin numeroa");
        return;
    } 

    var cardStatus = true;
    var cause = ": ";

    // Tarkistetaan, onko kortti edes olemassa tietokannassa
    card.getCard(request.body['cardno'], function(err, result) {
        let res = JSON.parse(JSON.stringify(result));
        //console.log(res[0]);
        
        if (err) {
            cardStatus = false;
            console.log(err);
            cause = cause + "database error";
        }
        else if ((res[0] == null) || (res[0] === undefined)) {
            cardStatus = false;
            cause = cause + "not in database";
        }
        else if (res[0]['state'] != null || res[0]['temp_restriction'] != null) {
            cardStatus = false;
            cause = cause + "card restricted ";
        }
        else if (res[0]['expiration']) {

        }

        response.send(cardStatus);
        console.log("Card " + request.body.cardno + " verified, result " + cardStatus + ( cardStatus ? "" : cause));
    });
});

module.exports = router;