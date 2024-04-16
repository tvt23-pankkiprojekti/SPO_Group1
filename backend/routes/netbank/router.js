/* The mecca of all netbank traffic, calls upon functions from different branches of action
*/

const express = require('express');
const router = express.Router();

const token = require('jsonwebtoken');
const path = require('path');
const login = require('./login');
const signup = require('./signup');
const deleteaccount = require('./deleteaccount');
const profilelookup  = require('./viewprofile');
const newservices = require('./newservices');
const userdata = require('./userdata');

const user = require('../../models/user_model'); // this is here for the /updateuser bandaid, can be removed later
const card = require('../../models/card_model');

const base_path = __dirname; // location of this file, used for path.join() commands

router.use(express.json());
router.use(express.urlencoded({ extended: false }));


// Purely here for turning all plaintext passwords in the database to encrypted ones so that you can
// actually login into the netbank with more users ('000' in the database won't match with '000' fed into bcrypt.compare())
        router.post('/updateuser', function(request, response) {
            let data = {
                'fname': request.body['fname'],
                'lname': request.body['lname'],
                'state': null,
                'temp_restriction': null,
                'password': request.body['password']
            };
            user.updateUser(request.body['userid'], data, function(err, result) {
                if (err) {
                    response.send(err);
                }
                else {
                    response.send(result);
                } 
            });
        });
// remove later
// Purely here for turning all plaintext passwords in the database to encrypted ones so that you can
// actually login into the netbank with more users ('000' in the database won't match with '000' fed into bcrypt.compare())
router.get('/addcard', function(request, response) {
    let data = {
        'id_card': "060006E2E7",
        'state': null,
        'id_owner': 3,
        'pincode': '888'
    };
    card.addCard(data, function(err, result) {
        if (err) {
            response.send(err);
        }
        else {
            response.send(result);
        } 
    });
});
// remove later


// Unauthenticated routes
router.get('/', function(request, response) {
    response.sendFile(path.join(base_path, "../../public/netbank.html"));
});

router.get('/login', function(request, response) {
    response.render('login');
});

router.post('/login', login.checkUser);

router.get('/logout', login.logOut);

router.get('/signup', function(request, response) {
    response.render('signup');
});

router.post('/signup', signup.addUser);

router.get('/deleteaccount', function(request, response) {
    response.render('deleteaccount');
});

router.delete('/deleteaccount', function(request, response) {
    deleteaccount.deleteUser(request, response);
});


//Authenticated routes
router.get('/home', function(request, response) {
    authenticateToken(request, response, function(request, response) {
        //console.log("Accessing home page");
        response.render('home', {name: request.cookies['simulbankusername']});
    });
});

router.get('/profile', function(request, response) {
    authenticateToken(request, response, profilelookup.getData);
});

router.get('/newservices', function(request, response) {
    authenticateToken(request, response, newservices.newServicesWindow);
});

router.get('/newservices/openaccount', function(request, response) {
    authenticateToken(request, response, function(request, response) {
        response.render('openaccount')
    });
});

router.post('/newservices/openaccount', function(request, response) {
    authenticateToken(request, response, function(request, response) {
        newservices.openAccount(request, response, 1)
    });
});

router.get('/newservices/getcard', function(request, response) {
    authenticateToken(request, response, function(request, response) {
        userdata.getUserData(request, response, function(err, user, cards, accounts) {
            if (err == true) {
                response.render('getcard', {error: "Something went wrong with getting your data"});
            }
            else {
                response.render('getcard', {accounts: accounts});
            }
        });
    });
});

router.post('/newservices/getcard', function(request, response) {
    if (request.body['account'] == 'credit') {
        console.log("Looking for credit card");
        newservices.openCreditCard(request, response);
    }
    else {
        console.log("looking for debit, account " + request.body['account']);
    }
});

router.get('/newservices/authorizecard', function(request, response) {
    authenticateToken(request, response, function(request, response) {
        response.render('authorizecard');
    });
});

function authenticateToken(request, response, next) {
    token.verify(request.cookies['simulbanktoken'], process.env.Web_Token, function(err, user) {
        //console.log("Verifying token");
        if (!err && user['userid'] == request.cookies['simulbankuserid']) {
            //console.log("Authentication successful, id " + request.cookies['simulbankuserid']);
            next(request, response);
        } 
        else {
            //console.log("failed verification, user id " + request.cookies['simulbankuserid']);
            response.render('unauthorized');
        }
    });
}

module.exports = router;