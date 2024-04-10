const user = require('../../models/user_model');
const path = require('path');
const base_path = __dirname;

// 
const login = {
    checkUser(request, response) {    
        let loginAccepted = false;
        let cause = "";

        // Check whether the user id exists
        user.getUser(request.body['user'], function(err, result) {
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

            let url = request.headers['origin'];
            if (loginAccepted == true) {
                response.cookie('simulbankuserid', request.body['user'], { expires: new Date(Date.now() + 1000000), httpOnly : true, secure : true});
                response.redirect(url + "/netbank/home");
            }
            else {
                response.redirect(url + "/netbank/failed_login");
            }
        });
    }
}

module.exports = login;