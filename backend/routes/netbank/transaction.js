const procedure = require('../../models/procedure_model');
const account = require('../../models/account_model');
const accountOwnership = require('../../models/account_ownership_model');

function findTransactionCapableAccounts(request, response) {
    account.allAccountsAccessibleByUser(request.cookies['simulbankuserid'], function(err, result) {
        if (err) {
            console.log(err);
            response.render('transaction', {error: "Error with getting your account data"});
        }
        else {
            let validAccounts = [];
            for (let i = 0; i < result.length; i++) {
                if (result[i]['state'] == null) {
                    validAccounts.push(result[i]);
                }
            }
            //console.log(result);
            //console.log(validAccounts);
            response.render('transaction', {accounts: validAccounts});
        }
    });
}

function accountToAccountTransaction(request, response) {
    console.log(request.body);
    let data = {
        'account_one': request.body['senderAccount'],
        'account_two': request.body['receiverAccount'],
        'amount': request.body['amount'],
        'description_one': 'Transfer to account ' + request.body['receiverAccount'],
        'description_two': 'Transfer from account ' + request.body['senderAccount']
    };

    procedure.accountToAccountTransaction(data, function(err, result) {
        if (err) {
            console.log(err);
            response.render('transaction', {error: "Something went wrong with the database"});
        }
        else {
            response.render('transaction', {success: "Transfer completed successfully!"});
        }
    });
}

module.exports = {
    findTransactionCapableAccounts,
    accountToAccountTransaction
}