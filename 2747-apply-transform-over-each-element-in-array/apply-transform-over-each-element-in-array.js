/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const len = arr.length;
    const res = new Array(len);
    for (let i = 0; i < len; ++i) {
        res[i] = fn(arr[i], i);
    }
    return res;
};