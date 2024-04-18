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

router.get('/listAllUsers', function(request, response) {
    usercontrols.listAllUsers(request, response);
});

router.put('/updateuser', function(request, response) {
    usercontrols.updateUser(request, response);
});

router.get('/getuserbyuserid', function(request, response) {
    usercontrols.getUser(request, response);
});

module.exports = router;