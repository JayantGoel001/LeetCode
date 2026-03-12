class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int> dp(2, 0);
        int maxi = 0;
        int length = 0;

        int start = 0;
        for(int i=0;i<nums.size();i++) {
            dp[nums[i]]++;
            while(start <= i && dp[0] > k) {
                dp[nums[start++]]--;
            }
            
            maxi = max(maxi, dp[0] + dp[1]);
        }

        return maxi;
    } 
};