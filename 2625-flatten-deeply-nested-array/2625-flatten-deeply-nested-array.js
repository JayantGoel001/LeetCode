var flat = function (arr, n) {
    
    // if n is 0, no flattening is required, hence return the original array
    if(n == 0){
        return arr;
    }
    
    // create an answer array to store final result
    let answer = [];
    
    // traverse the array
    for(let i=0; i<arr.length; i++){
        
        // check if element is instance of array and depth is not equal to 0
        if(n>0 && Array.isArray(arr[i])){
            
            // recursively call the function for this array and push the flattened array to the answer array
            answer.push(...flat(arr[i], n-1));
        }
        // else directy push the current array
        else{
            answer.push(arr[i]);
        }
    }
    
    return answer;
}