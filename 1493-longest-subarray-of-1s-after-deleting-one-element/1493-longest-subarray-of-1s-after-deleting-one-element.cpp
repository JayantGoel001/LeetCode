class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> dp(2, 0);

        int maxi = 0;
        int start = 0;
        for(int i=0;i<nums.size();i++) {
            while(start <= i && dp[0] > 1) {
                dp[nums[start++]]--;
            }
            dp[nums[i]]++;
            maxi = max(maxi, dp[1] - (dp[0] == 1 ? 0 : 1));
        }

        return maxi;
    }
};