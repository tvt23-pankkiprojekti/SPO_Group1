/* The mecca of all netbank traffic, calls upon functions from different branches of action
*/

const express = require('express');
const router = express.Router();

const token = require('jsonwebtoken');
const path = require('path');
const login = require('./login');
const signup = require('./signup');
const profilelookup  = require('./viewprofile');

const base_path = __dirname; // location of this file, used for path.join() commands

router.use(express.json());
router.use(express.urlencoded({ extended: false }));

// Unauthenticated routes
router.get('/', function(request, response) {
    response.sendFile(path.join(base_path, "../../public/netbank.html"));
});

router.get('/login', function(request, response) {
    response.sendFile(path.join(base_path, "../../public/login.html"));
});

router.post('/login', function(request, response) {
    login.checkUser(request, response);
});

router.get('/signup', function(request, response) {
    response.sendFile(path.join(base_path, "../../public/signup.html"));
});

router.post('/signup', function(request, response) {
    signup.addUser(request, response);
});

router.get('/failed_signup', function(request, response) {
    response.sendFile(path.join(base_path, "../../public/failed_signup.html"));
});


//Authenticated routes
router.get('/home', function(request, response) {
    response.sendFile(path.join(base_path, "../../public/home.html"));
});

router.get('/profile', function(request, response) {
    authenticateToken(request, response, function(request, response) {
        profilelookup.getData(request, response);
    });
});

function authenticateToken(request, response, next) {
    token.verify(request.cookies['simulbanktoken'], process.env.Web_Token, function(err, user) {
        console.log("Verifying token");
        if (!err && user['userid'] == request.cookies['simulbankuserid']) {
            next(request, response);
        } 
        else {
            console.log("failed verification, user id " + request.cookies['simulbankuserid']);
            response.send(false);
        }
    });
}

module.exports = router;