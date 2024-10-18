class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max = 0;
        vector<int> dp(1 << 17, 0);

        // Initialize the empty subset
        dp[0] = 1;

        // Iterate through each number in the input array
        for (int num : nums) {
            for (int i = max; i >= 0; i--) {
                // For each existing subset, create a new subset by including
                // the current number
                dp[i | num] += dp[i];
            }
            // Update the maximum OR value
            max |= num;
        }

        return dp[max];
    }
};