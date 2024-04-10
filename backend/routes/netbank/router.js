const express = require('express');
const router = express.Router();

const path = require('path');
const bcrypt = require('bcrypt');
const login = require('./login');
const signup = require('./signup');
const profilelookup  = require('./viewprofile');

const base_path = __dirname;

router.use(express.json());
router.use(express.urlencoded({ extended: false }));

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

router.get('/home', function(request, response) {
    response.sendFile(path.join(base_path, "../../public/home.html"));
});

router.get('/profile', function(request, response) {
    profilelookup.getData(request, response);
});

module.exports = router;