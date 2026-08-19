/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if (obj === null || obj === undefined || typeof classFunction !== 'function') {
        return false;
    }

    let currObj = obj;
    
    // Wrap primitive types (e.g., numbers, strings, booleans) into their Object equivalents
    // so we can traverse their prototype chain.
    if (typeof currObj !== 'object' && typeof currObj !== 'function') {
        currObj = Object(currObj);
    }

    while (currObj !== null) {
        if (Object.getPrototypeOf(currObj) === classFunction.prototype) {
            return true;
        }
        currObj = Object.getPrototypeOf(currObj);
    }

    return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */