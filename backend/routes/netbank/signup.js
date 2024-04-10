const user = require('../../models/user_model');

const signup = {
    // Adds given user data to the database, 
    addUser(request, response) {
        // Trims the request down for the addUser() request
        var userObject = {
            'fname' : request.body['fname'],
            'lname' : request.body['lname'],
            'state' : null,
            'password' : request.body['password']
        };
        let url = request.headers['origin'];

        user.addUser(userObject, function(err, result) {
            if (err) {
                response.redirect(url + "/netbank/failed_signup");
            }
            else {
                console.log("New user added to database");
                response.cookie('simulbankuserid', result['insertid'], { expires: new Date(Date.now() + 1000000), httpOnly : true, secure : true});
                response.redirect(url + "/netbank/home");
            }
        });
    }
}

module.exports = signup;