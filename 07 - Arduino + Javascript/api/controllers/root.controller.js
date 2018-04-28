// --> API Config
const { mode, port } = require('../configs/api.config');

const test = (req, res) => {
    res
        .status(200)
        .send({
            success: true,
            message: 'API is online!',
            content: {
                mode,
                port
            }
        });
};

module.exports = { test };