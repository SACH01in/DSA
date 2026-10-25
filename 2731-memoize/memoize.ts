/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const cache = new Map();
    
    return function(...args) {
        const key = args.length === 1 ? args[0] : (args[0] + ',' + args[1]);
        
        if (cache.has(key)) {
            return cache.get(key);
        }
        
        const res = fn(...args);
        cache.set(key, res);
        return res;
    }
}