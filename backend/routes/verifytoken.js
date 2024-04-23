const token = require('jsonwebtoken');

function verify(request, response, next) {
    let header = request.headers['authorization']
    let tkn = header.split(' ')[1];
  
    console.log("token = "+ tkn);
    if (tkn == null) {
        console.log("No token sent");
        next("No token sent", request, response);
        return;
    }

    token.verify(JSON.parse(tkn), process.env.Web_Token, function(err, user) {
        if (err) {
            console.log(err);
            next("Invalid token", request, response)
        }
        else {
            next(null, request, response);
        }
    });
}

module.exports = {
    verify
}