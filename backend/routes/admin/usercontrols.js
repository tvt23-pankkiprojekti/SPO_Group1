/* Admin user management routes
*/

const user = require('../../models/user_model');

const usercontrols = {
    // Adds given user data to the database, 
    addUser(request, response) {
        console.log(request.body);
        // Trims the request down for the addUser() request
        var userObject = {
            'fname' : request.body['fname'],
            'lname' : request.body['lname'],
            'state' : null,
            'password' : request.body['password']
        };
        // If insufficient data was sent, better catch that now instead of blaming the database
        if (userObject['fname'] == null || userObject['lname'] == null || userObject['password'] == null) {
            response.send("400");
            return;
        }

        user.addUser(userObject, function(err, result) {
            if (err) {
                console.log(err);
                response.send("500");
            }
            else {
                console.log("New user added to database");
                response.send("200");
            }
        });
    },

    deleteUser(request, response) {
        var id_user = request.body['id_user'];
    
        user.deleteUser(id_user, function(err, result) {
            if (err) {
                console.log(err);
                response.send("500");
            }
            else {
                console.log("User deleted from database");
                response.send("200");
            }
        });
    },

    getAllUsers(request, response) {
        console.log(request.body);

        var userObject = {
            'fname' : request.body['fname'],
            'lname' : request.body['lname'],
            'state' : null,
            'password' : request.body['password']
        };

        if (!user) {
            response.status(400).send("Not all required data was received with the request");
            return;
        }

        user.getAllUsers(userObject, function(err, result) {
            if (err) {
                console.log(err);
                response.send("500");
            }
            else {
                console.log("Users listed");
                response.send("200").json(result);
            }
        });
    }
}

module.exports = usercontrols;