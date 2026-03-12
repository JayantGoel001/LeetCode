class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(3, 0);
        dp[1] = nums[0];

        for(int i=2;i<=nums.size();i++) {
            dp[i%3] = max(dp[(i - 1)%3], dp[(i - 2)%3] + nums[i - 1]);
        }

        return dp[nums.size()%3];
    }
};