/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const res = {};
    for (let i = 0, len = this.length; i < len; ++i) {
        const item = this[i];
        const key = fn(item);
        if (!res[key]) {
            res[key] = [];
        }
        res[key].push(item);
    }
    return res;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */