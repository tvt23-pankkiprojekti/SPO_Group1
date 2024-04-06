var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var cardVerificationRouter = require('./routes/verifycard');
var indexRouter = require('./routes/index');
var userRouter = require('./routes/user');
var cardRouter = require('./routes/card');
var accountRouter = require('./routes/account');
var transactionRouter = require('./routes/transaction');

const port = process.env.PORT || 3000;
var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.listen(port, function(request, response) {
    console.log("Sovellus pyörii");
});

app.use('/bankomat/verifycard', cardVerificationRouter);
app.use('/', indexRouter);
app.use('/users', userRouter);
app.use('/card', cardRouter);
app.use('/account', accountRouter);
app.use('/transaction', transactionRouter);
//app.use(authenticatetoken);

module.exports = app;