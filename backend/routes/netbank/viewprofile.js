const userdata = require('./userdata');
const tokenCheck = require('./verifytoken');

function getData(request, response) {
    tokenCheck.verify(request, response, function(err, request, response) {
        if (err) {
            console.log(err);
            response.send(false);
        }
        else {
    userdata.getUserData(request, response, function(err, cards, debitAccounts, creditAccounts, authorizedAccounts) {
        if (err) {
            response.render('profile', {error: "Something went wrong with getting your data"});
        }
        else {
            let accounts = debitAccounts.concat(creditAccounts);
            //console.log(accounts);
            response.render('profile', {name: request.cookies['simulbankusername'], id: request.cookies['simulbankuserid'], accounts: accounts, authorizedAccounts: authorizedAccounts, cards: cards});
        }
    });
}
});
}

module.exports = {
    getData
};