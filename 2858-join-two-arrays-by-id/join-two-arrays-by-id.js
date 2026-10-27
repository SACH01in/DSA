var join = function(arr1, arr2) {
    const map = new Map();
    for (let i = 0, len = arr1.length; i < len; ++i) {
        map.set(arr1[i].id, { ...arr1[i] });
    }
    for (let i = 0, len = arr2.length; i < len; ++i) {
        const item = arr2[i];
        if (map.has(item.id)) {
            map.set(item.id, { ...map.get(item.id), ...item });
        } else {
            map.set(item.id, { ...item });
        }
    }
    return Array.from(map.values()).sort((a, b) => a.id - b.id);
};