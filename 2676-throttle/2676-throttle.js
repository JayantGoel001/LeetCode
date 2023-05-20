var throttle = function(fn, t) {
  let timerId;
  let lastArgs;
  let shouldCall = true;

  function execute() {
    if (shouldCall && lastArgs) {
      fn(...lastArgs);
      lastArgs = null;
      shouldCall = false;
      setTimeout(() => {
        shouldCall = true;
        execute();
      }, t);
    }
  }

  return function(...args) {
    lastArgs = args;
    execute();
  };
};