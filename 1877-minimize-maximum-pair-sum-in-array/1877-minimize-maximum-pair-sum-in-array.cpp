class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxSum = 0;
        int size = nums.size();
        for(int i=0;i<size/2;i++){
            maxSum = max(maxSum,nums[i] + nums[size - i - 1]);
        }
        return maxSum;
    }
};