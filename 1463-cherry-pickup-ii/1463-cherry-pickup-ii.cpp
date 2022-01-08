class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (grid[0].size());
        vector<vector<int>> prev_dp(n, vector<int>(n));
        for (int row = 0; row < m; row++) {
            vector<vector<int>> current_dp(n, vector<int>(n));
            for (int c1 = 0; c1 < min(n, row + 1); c1++) {
                for (int c2 = max(0, n - 1 - row); c2 < n; c2++) {
                    int prev_max = 0;
                    for (int offset1 = max(0, c1 - 1); offset1 <= min(n - 1, c1 + 1); offset1++) {
                        for (int offset2 = max(0, c2 - 1); offset2 <= min(n - 1, c2 + 1); offset2++) {
                                prev_max = max(prev_max, prev_dp[offset1][offset2]);
                        }
                    }
                    if (c1 == c2)
                        current_dp[c1][c2] = prev_max + grid[row][c1];
                    else
                        current_dp[c1][c2] = prev_max + grid[row][c1] + grid[row][c2];
                }
            }
            prev_dp = current_dp;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, prev_dp[i][j]);    
            }
        }
        return res;
    }
};