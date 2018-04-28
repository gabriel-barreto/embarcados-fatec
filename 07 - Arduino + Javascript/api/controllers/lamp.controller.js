const lamp = require('../functions/lamp.functions');

const toggle = (req, res) => {
    // if (lamp.status) lamp.setOff();
    // else lamp.setOn();

    res
        .status(200)
        .send({ success: true, status: lamp.status });
};

module.exports = { toggle };