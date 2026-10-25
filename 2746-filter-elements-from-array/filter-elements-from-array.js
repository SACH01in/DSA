var filter = function(arr, fn) {
    const res = [];
    const len = arr.length;
    let size = 0;

    for (let i = 0; i < len; ++i) {
        if (fn(arr[i], i)) {
            res[size++] = arr[i];
        }
    }

    return res;
};