class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        int leftSum = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];
            
            int leftCount = i;
            int rightCount = n - 1 - i;
            
            int leftTotal = leftCount * nums[i] - leftSum;
            int rightTotal = rightSum - rightCount * nums[i];
            
            ans.push_back(leftTotal + rightTotal);
            leftSum += nums[i];
        }
        
        return ans;
    }
};