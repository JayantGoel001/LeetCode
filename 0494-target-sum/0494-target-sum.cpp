class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> dp(2 * totalSum + 1, 0);

        // Initialize the first row of the DP table
        dp[nums[0] + totalSum] = 1;    // Adding nums[0]
        dp[-nums[0] + totalSum] += 1;  // Subtracting nums[0]

        // Fill the DP table
        for (int index = 1; index < nums.size(); index++) {
            vector<int> next(2 * totalSum + 1, 0);
            for (int sum = -totalSum; sum <= totalSum; sum++) {
                if (dp[sum + totalSum] > 0) {
                    next[sum + nums[index] + totalSum] += dp[sum + totalSum];
                    next[sum - nums[index] + totalSum] += dp[sum + totalSum];
                }
            }
            dp = next;
        }

        // Return the result if the target is within the valid range
        return abs(target) > totalSum ? 0 : dp[target + totalSum];
    }
};