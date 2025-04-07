class Solution {
public:
    bool canPartition(vector<int> &nums, int x, int sum, vector<vector<int>> &dp) {
        if (sum == 0) return true;
        if (x == 0) return false;

        if(dp[x][sum] == -1) {
            dp[x][sum] = canPartition(nums, x - 1, sum, dp);

            if (sum >= nums[x]) {
                dp[x][sum] |= canPartition(nums, x - 1, sum - nums[x], dp);
            }
        }

        return dp[x][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums) sum += it;

        if (sum % 2) return false;

        vector<vector<int>> dp(nums.size(), vector<int> (sum/2 + 1, -1));

        return canPartition(nums, nums.size() - 1, sum / 2, dp);
    }
};