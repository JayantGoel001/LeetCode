class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            auto pos = lower_bound(dp.begin(),dp.end(),nums[i]);
            
            if(pos != dp.end()){
                dp[pos - dp.begin()] = nums[i];
            }else{
                dp.push_back(nums[i]);
            }
        }
        
        return dp.size();
    }
};