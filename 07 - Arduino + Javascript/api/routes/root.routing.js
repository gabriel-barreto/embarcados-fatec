// --> Dependencies
const Router = require('express').Router();

// --> Controller
const controller = require('../controllers/root.controller');

Router.get('/run', controller.test);

module.exports = Router;