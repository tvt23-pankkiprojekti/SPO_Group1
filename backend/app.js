const express = require('express');
const path = require('path');
const cookieParser = require('cookie-parser');
const logger = require('morgan');

const netbankRouter = require('./routes/netbank/router');
const cardVerificationRouter = require('./routes/verifycard');
const adminRouter = require('./routes/admin/router');
const viewCardRouter = require('./routes/viewcard');
const loginRouter = require('./routes/login');
const transactionRouter = require('./routes/transaction');

const swagger = require('swagger-ui-express');
const swaggerDoc = require('./swagger.json');

const port = process.env.PORT || 3000;
const app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));
app.use('/swagger', swagger.serve, swagger.setup(swaggerDoc));

app.listen(port, function(request, response) {
    console.log("Server online");
});

app.use('/netbank', netbankRouter);
app.use('/admin', adminRouter);
app.use('/bankomat/verifycard', cardVerificationRouter);
app.use('/bankomat/viewprofile', viewCardRouter);
app.use('/bankomat/login', loginRouter);
app.use('/bankomat/transaction', transactionRouter);
//app.use(authenticatetoken);

module.exports = app;