class EventEmitter {
    constructor() {
        this.events = new Map();
    }

    subscribe(event, cb) {
        if (!this.events.has(event)) {
            this.events.set(event, []);
        }
        const listeners = this.events.get(event);
        listeners.push(cb);
        
        return {
            unsubscribe: () => {
                const index = listeners.indexOf(cb);
                if (index !== -1) {
                    listeners.splice(index, 1);
                }
            }
        };
    }

    emit(event, args = []) {
        if (!this.events.has(event)) {
            return [];
        }
        const listeners = this.events.get(event);
        const res = new Array(listeners.length);
        for (let i = 0, len = listeners.length; i < len; ++i) {
            res[i] = listeners[i](...args);
        }
        return res;
    }
}