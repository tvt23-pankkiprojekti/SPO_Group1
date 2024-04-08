const express = require('express');
const router = express.Router();
var path = require('path');

var basepath = path.join(__dirname, '..');

router.get('/', function(request, response) {
    response.sendFile(path.join(basepath, '/public/homepage.html'));
});

router.get('/login', function(request, response) {
    response.sendFile(path.join(basepath, '/public/loginpage.html'));
});

module.exports = router;