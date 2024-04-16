const userdata = require('./userdata');

function getData(request, response) {
    userdata.getUserData(request, response, function(err, user, cards, accounts) {
        if (err == true) {
            response.render('profile', {error: "Something went wrong with getting your data"});
        }
        else {
            response.render('profile', {name: user['username'], id: user['id_user'], accounts: accounts, cards: cards});
        }
    })
}

module.exports = {
    getData
};