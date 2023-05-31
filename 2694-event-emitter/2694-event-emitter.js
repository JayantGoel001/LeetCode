class EventEmitter {
    constructor() {
        this.events = {};
    }

    subscribe(event, cb) {
      this.events[event] = this.events[event] ?? [];
      this.events[event].push(cb);

      return {
        unsubscribe: () => {
          this.events[event] = this.events[event].filter(f => f !== cb);
          //To avoid memory leaks adding a cleanup condition
          if (this.events[event].length === 0) { delete this.events[event] }
        },
      };
    }

    emit(event, args = []) {
        if (!(event in this.events)) return [];
        return this.events[event].map(f => f(...args));
    }
}