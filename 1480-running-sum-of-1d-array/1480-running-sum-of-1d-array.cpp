class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int prev = 0;
        for(int i=0;i<nums.size();i++){
            nums[i] += prev;
            prev  = nums[i];
        }
        return nums;
    }
};