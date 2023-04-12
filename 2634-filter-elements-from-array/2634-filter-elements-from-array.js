/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let x = []
    for(let i = 0;i < arr.length;i++){
        if(fn(arr[i], i)){
            x.push(arr[i]);
        }
    }
    return x;
};