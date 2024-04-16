var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(request, res, next) {
  res.render('index', { title: 'SimulBank' });
});

router.post('/', function(request, response) {
  response.json("Vastaus");
});

router.delete('/', function(request, response) {
  response.json(":))");
});

module.exports = router;