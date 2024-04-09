var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var netbankRouter = require('./routes/netbank');
var adminRouter = require('./routes/admin');
var cardVerificationRouter = require('./routes/verifycard');
var loginRouter = require('./routes/login');
var viewprofileRouter = require('./routes/viewprofile');
var transactionRouter = require('./routes/transaction');

const port = process.env.PORT || 3000;
var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.listen(port, function(request, response) {
    console.log("Server online");
});

app.use('/netbank', netbankRouter);
app.use('/admin', adminRouter);
app.use('/bankomat/verifycard', cardVerificationRouter);
app.use('/bankomat/login', loginRouter);
app.use('/bankomat/viewprofile',viewprofileRouter);
app.use('/bankomat/transaction', transactionRouter);
//app.use(authenticatetoken);

module.exports = app;