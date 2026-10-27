var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const len = functions.length;
        if (len === 0) {
            resolve([]);
            return;
        }
        
        const res = new Array(len);
        let count = 0;
        let isRejected = false;
        
        for (let i = 0; i < len; ++i) {
            functions[i]()
                .then(val => {
                    if (isRejected) return;
                    res[i] = val;
                    count++;
                    if (count === len) {
                        resolve(res);
                    }
                })
                .catch(err => {
                    if (!isRejected) {
                        isRejected = true;
                        reject(err);
                    }
                });
        }
    });
};