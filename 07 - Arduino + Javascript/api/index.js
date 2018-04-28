const express = require('express');
const bodyParser = require('body-parser');
const logger = require('morgan');

const app = express();
app.use(bodyParser.json());
app.use(logger('tiny'));

const { mode, port } = require('./configs/api.config');

const middleware = {
    default: require('./middlewares/default.middleware'),
};

const router = {
    root: require('./routes/root.routing'),
    lamp: require('./routes/lamp.routing'),
};

app.use('/', middleware.default);
app.use('/api/v1/', router.root);
app.use('/api/v1/lamp', router.lamp);

app.listen(port, () => {
    console.log(`[API] Port: ${port}`);
    console.log(`[API] Mode: ${mode}`);
});