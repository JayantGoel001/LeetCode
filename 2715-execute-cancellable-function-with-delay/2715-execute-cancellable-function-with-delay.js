const cancellable = function(fn, args, t) {
    const timeoutHandle = setTimeout(() => fn(...args), t)    
    return () => clearTimeout(timeoutHandle)
};