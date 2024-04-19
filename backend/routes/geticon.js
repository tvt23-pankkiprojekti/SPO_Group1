const express = require('express');
const router = express.Router();
const geticon = require('../models/user_model');

router.get('/icon', function(request, response) {

    geticon.getIcon(request.body, function(err, result) {
        if (err) {
            response.send(err);
            console.log(error);
        } else {
            console.log(result);
            response.send(result);
        }
    });
});

module.exports = router;