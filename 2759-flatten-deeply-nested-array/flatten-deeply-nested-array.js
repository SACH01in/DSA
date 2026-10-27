var flat = function (arr, n) {
    const res = [];
    const helper = (items, depth) => {
        for (let i = 0, len = items.length; i < len; ++i) {
            const item = items[i];
            if (Array.isArray(item) && depth < n) {
                helper(item, depth + 1);
            } else {
                res.push(item);
            }
        }
    };
    helper(arr, 0);
    return res;
};