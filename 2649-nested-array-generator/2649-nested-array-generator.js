/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function* (arr) {
    if(!Array.isArray(arr)) {
        yield arr
        return
    }

    for(let i = 0; i < arr.length; i++) {
        yield* inorderTraversal(arr[i])
    }
};