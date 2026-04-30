class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, INT_MIN)));
        dp[0][0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == INT_MIN) continue;
                    if (i + 1 < m) {
                        int val = grid[i + 1][j];
                        int cost = (val == 0 ? 0 : 1);
                        if (c + cost <= k) {
                            dp[i + 1][j][c + cost] =
                                max(dp[i + 1][j][c + cost], dp[i][j][c] + val);
                        }
                    }
                    if (j + 1 < n) {
                        int val = grid[i][j + 1];
                        int cost = (val == 0 ? 0 : 1);
                        if (c + cost <= k) {
                            dp[i][j + 1][c + cost] =
                                max(dp[i][j + 1][c + cost], dp[i][j][c] + val);
                        }
                    }
                }
            }
        }
        int ans = INT_MIN;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m - 1][n - 1][c]);
        }
        return ans < 0 ? -1 : ans;
    }
};