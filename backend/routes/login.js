const express = require('express');
const router = express.Router();
const card = require('../models/card_model');
const card2 = require('./card_model2'); // Renamed card2 to avoid conflict
const { addFailedLoginAttempt, isCardBlocked } = require('./failedAttempts');
const bcrypt = require('bcrypt');
const jwt = require('jsonwebtoken');

router.post('/', function(request, response) {
    const cardNumber = request.body.card;
    const pin = request.body.pincode;

    if (!cardNumber || !pin) {
        console.log('Missing information');
        return response.status(400).json({ error: 'Missing information' });
    }

    isCardBlocked(cardNumber, function(err, blocked) {
        if (err) {
            console.error("error checking", err);
            return response.status(500).json({ error: 'Server error' }); // Corrected 'server error' to a string
        }

        if (blocked) {
            console.log("Card blocked. Please try again later");
            return response.status(401).json({ error: "Card Blocked. Please try again later." }); // Added closing quote
        }

        card.login(cardNumber, function(err, result) {
            if (err) {
                console.log(err.errno);
                return response.status(500).json({ error: err.errno }); // Removed comma
            }

            if (result.length > 0) {
                bcrypt.compare(pin, result[0].pincode, function(err, compareResult) {
                    if (compareResult) {
                        console.log('Login successful');
                        const token = genToken({ card: cardNumber });
                        response.json(token);
                    } else {
                        console.log("Incorrect pincode");
                        addFailedLoginAttempt(cardNumber, function(err) {
                            if (err) {
                                console.error("error adding failed login attempt");
                            }
                        }); // Corrected closing parentheses
                        response.status(401).json({ error: 'Incorrect pincode' });
                    }
                });
            } else {
                console.log("Card not found");
                response.status(404).json({ error: "Card not found" });
            }
        });
    });
});

function genToken(value) {
    return jwt.sign(value, process.env.Web_Token, { expiresIn: '600s' });
}

module.exports = router;