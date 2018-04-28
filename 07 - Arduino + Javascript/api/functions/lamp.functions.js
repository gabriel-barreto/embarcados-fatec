const five = require('johnny-five');

const status = false;

const setOn = () => {
    const board = new five.Board();
    board.on('ready', () => {
        const led = new five.Led(13);
        led.on();
        status = true;
    });
};

const setOff = () => {
    const board = new five.Board();
    board.on('ready', () => {
        const led = new five.Led(13);
        led.off();
        status = false;
    });
};

module.exports = { setOn, setOff, status };
