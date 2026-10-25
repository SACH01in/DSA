type Fn = (...args: any[]) => any;

function once(fn: Fn): Fn {
    let called = false;
    return function(...args: any[]) {
        if (!called) {
            called = true;
            return fn(...args);
        }
    };
}