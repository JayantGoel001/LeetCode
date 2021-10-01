class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp;
        
        for(int i=0;i<nums.size();i++){
            auto pos = lower_bound(dp.begin(),dp.end(),nums[i]);
            
            if(pos == dp.end()){
                dp.push_back(nums[i]);
            }else{
                dp[pos - dp.begin()] = nums[i];
            }
        }
        
        return dp.size();
    }
};