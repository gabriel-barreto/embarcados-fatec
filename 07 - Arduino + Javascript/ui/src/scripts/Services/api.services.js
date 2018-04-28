import config from '../Configs/api.config';

/**
 * Inverte o atual status da lampada!
 * 
 */
const toggle = () => {
    return fetch(`${config.url}${config.versions.v1}/lamp/toggle`)
        .then((apiResponse) => apiResponse.json())
        .then((jsonResponse) => jsonResponse)
        .catch((err) => new Error(err));
};


export { toggle };