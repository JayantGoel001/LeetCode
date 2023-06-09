var cancellable = function(fn, args, t) {
  var timerId;
  var time = 0;
  var result = [];

  function executeFn() {
    var returnedValue = fn.apply(null, args);
    result.push({ time: time, returned: returnedValue });
    time += t;
  }

  function cancelFn() {
    clearInterval(timerId);
  }

  executeFn();
  timerId = setInterval(executeFn, t);

  return cancelFn;
};
