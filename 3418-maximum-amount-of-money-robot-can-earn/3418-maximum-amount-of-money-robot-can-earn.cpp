class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins[0].size();
        vector dp(n + 1, vector<int>(3, INT_MIN / 2));

        for (int i = 0; i < 3; i++) {
            dp[1][i] = 0;
        }
        for (auto& row : coins) {
            for (int j = 1; j <= n; j++) {
                int x = row[j - 1];
                dp[j][2] = max(
                    {dp[j - 1][2] + x, dp[j][2] + x, dp[j - 1][1], dp[j][1]});
                dp[j][1] = max(
                    {dp[j - 1][1] + x, dp[j][1] + x, dp[j - 1][0], dp[j][0]});
                dp[j][0] = max(dp[j - 1][0], dp[j][0]) + x;
            }
        }

        return dp[n][2];
    }
};