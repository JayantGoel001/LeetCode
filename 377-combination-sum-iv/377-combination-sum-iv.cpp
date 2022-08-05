class Solution {
public:
    vector<int> dp;
    
    int getCS(vector<int>& nums, int target){
        
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        
        if(dp[target] == -1){
            dp[target] = 0;
            for(auto it : nums){
                dp[target] += getCS(nums,target - it);
            }
        }
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target + 1,-1);
        
        return getCS(nums,target);
    }
};