const user = require('../../models/user_model');
const path = require('path');
const bcrypt = require('bcrypt');
const token = require('jsonwebtoken');

const base_path = __dirname;
 
const login = {
    // Checks the credentials of a single user for access
    checkUser(request, response) {    
        let loginAccepted = false;
        let cause = "";

        // Check whether the user id exists
        user.getUser(request.body['user'], function(err, result) {
            let res = JSON.parse(JSON.stringify(result));
            
            // If database check leads to an error
            if (err) {
                console.log(err);
                response.render('login', {error: "Database error"});
            }
            // If nothing is returned from the database
            else if ((res[0] == null) || (res[0] === undefined)) {
                response.render('login', {error: "Wrong ID or password"});
            }
            else {
                // Gets the user's password from the database
                user.login(request.body['user'], function(err, result) {
                    // The url the request was sent from (e.g. "https://simulation-bank.onrender-com")
                    let url = request.headers['origin'];
                    // Checks for a returned password (hash)
                    if(result.length > 0) {
                        // Compares it to the sent one, bear in mind that the non-hashed passwords in the database return a false result
                        bcrypt.compare(request.body['password'], result[0].password, function(err, compareResult){
                            if(err) {
                                response.render('login', {error: "Verification error"});
                            }
                            // compareResult = true or false, answers whether the comparison went ok
                            else if(compareResult == false) {
                                response.render('login', {error: "Wrong ID or password"});
                            }
                            // Only give out the knowledge that an account is restricted if the logger-in can provide the correct password
                            else if (res[0]['state'] != null || res[0]['temp_restriction'] != null) {
                                response.render('login', {error: "Account restricted"});
                            }
                            else {
                                //console.log(compareResult);
                                // Adds cookies for the user id and login token to the response
                                response.cookie('simulbankuserid', request.body['user'], { expires: new Date(Date.now() + 1000000), httpOnly : true, secure : true});
                                response.cookie('simulbankusername', res[0]['fname'] + " " + res[0]['lname'], { expires: new Date(Date.now() + 1000000), httpOnly : true, secure : true});
                                let token = generateToken({userid: request.body['user']});
                                response.cookie('simulbanktoken', token, { expires: new Date(Date.now() + 1000000), httpOnly : true, secure : true});
                                response.redirect(url + "/netbank/home");
                            }
                        });
                    }
                    else {
                        response.render('login', {error: "Undefined error"});
                    }
                });
            }
        });
    },
    logOut(request, response, next) {
        if (request.cookies['simulbankuserid']) {
            response.cookie('simulbankuserid', null, {expires: new Date(1)});
        }
        if (request.cookies['simulbanktoken']) {
            response.cookie('simulbanktoken', null, {expires: new Date(1)});
        }
        next(request, response);
    }
}

function generateToken(id) {
    return token.sign(id, process.env.Web_Token, {expiresIn: '600s'});
}

module.exports = login;