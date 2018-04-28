const Router = require('express').Router();

const controller = require('../controllers/lamp.controller');

Router.get('/toggle', controller.toggle);

module.exports = Router;