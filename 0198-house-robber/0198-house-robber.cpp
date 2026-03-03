class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(3, 0);
        dp[0] = nums[0];
        dp[1] = max(nums.size() > 1 ? nums[1] : 0, nums[0]);

        for(int i=2;i<nums.size();i++) {
            dp[i % 3] = max(nums[i] + dp[(i - 2 + 3) % 3], dp[(i - 1 + 3) % 3]);
        }

        return dp[(nums.size() - 1 + 3) % 3];
    }
};