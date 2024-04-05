var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');
var cardRouter = require('./routes/card');
var accountRouter = require('./routes/account');
var transactionRouter = require('./routes/transaction');
var adminRouter = require('./routes/admin');
var cardAttachedAccountRouter = require('./routes/card_attached_account');
var userRouter = require('./routes/user');
var accountOwnershipRouter = require('./routes/account_ownership');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/users', usersRouter);
app.use('/card', cardRouter);
app.use('/account', accountRouter);
app.use('/transaction', transactionRouter);
app.use('/admin', adminRouter);
app.use('/cardattached', cardAttachedAccountRouter);
app.use('/user', userRouter);
app.use('/accountowner', accountOwnershipRouter);
//app.use(authenticatetoken);

module.exports = app;