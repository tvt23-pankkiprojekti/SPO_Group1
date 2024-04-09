var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var netbankRouter = require('./routes/netbank');
var cardVerificationRouter = require('./routes/verifycard');
var indexRouter = require('./routes/index');
var userRouter = require('./routes/user');
var cardRouter = require('./routes/card');
var accountRouter = require('./routes/account');
var transactionRouter = require('./routes/transaction');
var viewtransactionsRouter = require('./routes/view_transactions');
var adminRouter = require('./routes/admin');
var cardAttachedAccountRouter = require('./routes/card_attached_account');
var accountOwnershipRouter = require('./routes/account_ownership');

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

app.use('/netbank', netbankRouter);
app.use('/bankomat/verifycard', cardVerificationRouter);
app.use('/', indexRouter);
app.use('/user', userRouter);
app.use('/card', cardRouter);
app.use('/account', accountRouter);
app.use('/transaction', transactionRouter);
app.use('/view_transactions', viewtransactionsRouter);
app.use('/admin', adminRouter);
app.use('/cardattached', cardAttachedAccountRouter);
app.use('/accountowner', accountOwnershipRouter);
//app.use(authenticatetoken);

module.exports = app;