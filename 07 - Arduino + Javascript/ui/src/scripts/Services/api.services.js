import config from '../Configs/api.config';

const turnOn = () => {
    fetch(`${config.url}${config.versions.v1}/turnon`)
        .then((apiResponse) => apiResponse.json())
        .then((jsonResponse) => console.log(jsonResponse))
        .catch((err) => console.error(err));
};

const turnOff = () => {
    fetch(`${config.url}${config.versions.v1}/turnoff`)
        .then((apiResponse) => apiResponse.json())
        .then((jsonResponse) => console.log(jsonResponse))
        .catch((err) => console.error(err));
};

const sayHello = () => {
    console.log('Hello world!');
};

export { turnOn, turnOff, sayHello };