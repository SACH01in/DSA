var join = function(arr1, arr2) {
    const map = {};
    for (let i = 0, len = arr1.length; i < len; ++i) {
        const item = arr1[i];
        map[item.id] = Object.assign({}, item);
    }
    for (let i = 0, len = arr2.length; i < len; ++i) {
        const item = arr2[i];
        if (map[item.id] !== undefined) {
            Object.assign(map[item.id], item);
        } else {
            map[item.id] = Object.assign({}, item);
        }
    }
    const ids = Object.keys(map);
    ids.sort((a, b) => a - b);
    const res = new Array(ids.length);
    for (let i = 0, len = ids.length; i < len; ++i) {
        res[i] = map[ids[i]];
    }
    return res;
};