class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        
        for(auto it : nums){
            int pos = lower_bound(dp.begin(),dp.end(),it) - dp.begin();
            if(pos != dp.size()){
                 dp[pos] = it;
            }else{
                dp.push_back(it);
            }
        }
        return dp.size();
    }
};