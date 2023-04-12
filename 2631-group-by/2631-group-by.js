/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    const x = {};
    for(let i = 0;i < this.length; i++){
        if(x[fn(this[i])] == undefined){
            x[fn(this[i])] = [];
        }
        x[fn(this[i])].push(this[i]);
    }
    return x;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */