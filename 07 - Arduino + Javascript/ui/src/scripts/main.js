import '../stylesheets/main.sass';

import * as apiService from './Services/api.services';

/**
 * Search elements in the DOM tree and returns an array with found elements
 *
 * @param { String } query Used to search in the DOM tree for the elements
 * @returns { Array } Elements found in the DOM parsed into an array
 */
HTMLDocument.prototype.getElement = function(query) {
    const nodeElements = document.querySelectorAll(query);
    return Array.prototype.slice.call(nodeElements);
};

function toggleLights() {
    const [ on ] = document.getElement('.is-on');
    const [ off ] = document.getElement('.is-off');

    on.classList.remove('is-on');
    on.classList.add('is-off');
    off.classList.remove('is-off');
    off.classList.add('is-on');
}

window.addEventListener('DOMContentLoaded', () => {
    const lights = document.getElement('.light');
    lights.every((light) => {
        light.addEventListener('click', (event) => {
            toggleLights();
        });
        return true;
    });
});
