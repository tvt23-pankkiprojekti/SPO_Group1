const user = require('../../models/user_model');

const deleteaccount = {
    deleteUser(request, response) {
        var userObject = {
            'fname' : request.body['fname'],
            'lname' : request.body['lname'],
            'password' : request.body['password']
        };

        let url = request.headers['origin'];

        user.deleteUser(userObject, function(err, result) {
            if (err) {
                response.render('deleteaccount', {error: "Error deleting account"});
            } else {
                console.log("User account deleted from database");
                response.redirect('/deleted');
            }
        });
    }
}

module.exports = deleteaccount;
