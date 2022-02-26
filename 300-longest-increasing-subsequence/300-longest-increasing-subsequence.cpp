class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] < nums[j] && dp[j] <= dp[i] + 1){
                    dp[j] = dp[i] + 1;
                }
            }
        }
        int maxi = 0;
        for(auto it : dp){
            maxi = max(maxi,it);
        }
        return maxi;
    }
};