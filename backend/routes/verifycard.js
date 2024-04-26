const express = require('express');
const router = express.Router();
const card = require('../models/card_model');

/* {{url}}/bankomat/verifycard, kutsutaan kun halutaan tarkistaa onko maattiin syötetty kortti
pankin listoilla & käytettävissä, mukaan laitetaan kortin numero
*/
router.post('/', function(request, response) {
    // Before proceeding, check that a card no was sent
    if (!request.body.card) {
        response.send(false);
        return;
    } 

    verifyCard(request, response);
});

// Takes a card no in the request (name 'cardno'), performs a check in the database to verify whether the 
// card is usable
function verifyCard(request, response) {
    // Whether the card is accepted
    var cardStatus = false;
    var cause = ": ";

    // Tarkistetaan, onko kortti olemassa tietokannassa
    card.getCard(request.body.card, function(err, result) {
        //console.log(result);
        let res = JSON.parse(JSON.stringify(result));
        //console.log(res);
        
        // If database check leads to an error
        if (err) {
            console.log(err);
            cause = cause + "database error";
        }
        // If nothing is returned from the database
        else if ((res[0] == null) || (res[0] === undefined)) {
            cause = cause + "not in database";
        }
        // If the card's state or temp restriction brings up something (null = nothing of note)
        else if (res[0]['state'] != null || res[0]['temp_restriction'] != null) {
            cause = cause + "card restricted";
        }
        else {
            cardStatus = true;
            // Compare the current date to the card's expiration date
            // Code below transforms card & current date to 'YYYY-MM-DD' formats
            let cardDate = new Date(res[0]['expiration']).toISOString().split('T')[0];
            let thisDate = new Date(Date.now()).toISOString().split('T')[0];
            if (cardDate < thisDate) {
                card.updateExpiration(res[0]['id_card']);
                cardStatus = false;
                cause = cause + "card expired"
            }
        }

        // True-false-response sent back, console gets message with id_card, success/failure & reason for failure if applicable
        response.send(cardStatus);
        console.log("Card " + request.body['card'] + " verified, result " + cardStatus + (cardStatus ? "" : cause));
    });
}

module.exports = router;