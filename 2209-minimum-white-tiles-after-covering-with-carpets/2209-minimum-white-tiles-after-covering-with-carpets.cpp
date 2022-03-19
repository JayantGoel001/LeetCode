class Solution {
public:
    int minimumWhiteTiles(string s, int nc, int l) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(nc + 1));
        for (int i = 1; i <= n; ++i) {
            for (int k = 0; k <= nc; ++k) {
                int jump = dp[i - 1][k] + s[i - 1] - '0';
                int cover = k > 0 ? dp[max(i - l, 0)][k - 1] : 1000;
                dp[i][k] = min(cover, jump);
            }
        }
        return dp[n][nc];
    }
};