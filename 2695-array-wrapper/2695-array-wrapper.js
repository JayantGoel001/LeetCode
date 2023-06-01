var ArrayWrapper = function(nums) {
    this.nums = nums;
};

ArrayWrapper.prototype.valueOf = function() {
    let sum = 0;
    for (let i = 0; i < this.nums.length; i++) {
        sum += this.nums[i];
    }
    return sum;
}

ArrayWrapper.prototype.toString = function() {
    return "[" + this.nums.join(',') + "]";
}