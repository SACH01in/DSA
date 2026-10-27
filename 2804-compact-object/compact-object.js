/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if (obj === null || typeof obj !== 'object') return obj;
    
    if (Array.isArray(obj)) {
        const res = [];
        for (let i = 0, len = obj.length; i < len; ++i) {
            const val = obj[i];
            if (val) {
                res.push(typeof val === 'object' ? compactObject(val) : val);
            }
        }
        return res;
    }
    
    const res = {};
    for (const key in obj) {
        const val = obj[key];
        if (val) {
            res[key] = typeof val === 'object' ? compactObject(val) : val;
        }
    }
    return res;
};