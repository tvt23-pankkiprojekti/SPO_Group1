const express = require('express');
const router = express.Router();
const user = require('../models/user_model');
const path = require('path');
const bcrypt = require('bcrypt');

const base_path = __dirname;

router.use(express.json());
router.use(express.urlencoded({ extended: false }));

router.get('/', function(request, response) {
    response.sendFile(path.join(base_path, "../public/netbank.html"));
});

router.get('/login', function(request, response) {
    response.sendFile(path.join(base_path, "../public/login.html"));
});

router.post('/login', function(request, response) {
    checkUser(request, response);
});

router.get('/signup', function(request, response) {
    response.sendFile(path.join(base_path, "../public/signup.html"));
});

router.post('/signup', function(request, response) {
    addUser(request, response);
});

// Personal home page, some functionality related to the id number to be added later
router.get('/home-u:id', function(request, response) {
    response.sendFile(path.join(base_path, "../public/home.html"));
});

router.get('/failed_signup', function(request, response) {
    response.sendFile(path.join(base_path, "../public/failed_signup.html"));
});

// 
function checkUser(request, response) {    
    let loginAccepted = false;
    let cause = "";

    // Check whether the user id exists
    user.getUser(request.body.user, function(err, result) {
        let res = JSON.parse(JSON.stringify(result));
        
        // If database check leads to an error
        if (err) {
            console.log(err);
            cause = cause + "Database error";
        }
        // If nothing is returned from the database
        else if ((res[0] == null) || (res[0] === undefined)) {
            cause = cause + "ID not in database";
        }
        // If the card's state or temp restriction brings up something (null = nothing of note)
        else if (res[0]['state'] != null || res[0]['temp_restriction'] != null) {
            cause = cause + "Account restricted";
        }
        else {
            loginAccepted = true;
        }

        console.log(cause);

        if (loginAccepted == true) {
            response.sendFile(path.join(base_path, "../public/home.html"));
        }
        else {
            response.sendFile(path.join(base_path, "../public/failed_login.html"));
        }
    });
}

// Adds given user data to the database, 
function addUser(request, response) {
    // Trims the request down for the addUser() request
    var userObject = {
        'fname' : request.body.fname,
        'lname' : request.body.fname,
        'state' : null,
        'password' : request.body.password
    };
    let url = request.headers['origin'];

    user.addUser(userObject, function(err, result) {
        if (err) {
            response.redirect(url + "/netbank/failed_signup");
        }
        else {
            console.log("New user added to database");
            // 
            user.getUserByName(request.body.fname, request.body.laname, function(err, result) {
                let res = JSON.parse(JSON.stringify(result));
                let id_addon;
                if (err) {
                    id_addon = "";
                }
                else {
                    console.log("New user's ID: " + res[0]['id_user']);
                    id_addon = "-u" + res[0]['id_user'];
                }

                response.redirect(url + "/netbank/home" + id_addon);
            });
        }
    });
}

module.exports = router;