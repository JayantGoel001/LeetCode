/**
 * @param {Function} fn
 * @return {Function}
 */
var curry = function(fn) {
    const v = [];
    return function curried(...args) {
        v.push(...args);
        return fn.length > v.length ? curried : fn(...v);
    };
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */
