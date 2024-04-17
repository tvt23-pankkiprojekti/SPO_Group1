/* Redirects admin requests to various branches of the admin folder

*/

const express = require('express');
const router = express.Router();
const usercontrols = require('./usercontrols');

// 
router.post('/adduser', function(request, response) {
    usercontrols.addUser(request, response);
});

router.delete('/deleteaccount', function(request, response) {
    usercontrols.deleteUser(request, response);
});

module.exports = router;