class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        const int pathLen = n + m - 1;

        if (pathLen % 2 == 1) {
            return false;
        }
        if (grid[0][0] != '(' || grid[n - 1][m - 1] != ')') {
            return false;
        }

        vector<vector<bitset<201>>> dp(n, vector<bitset<201>>(m));

        dp[0][0].set(1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                const int change = grid[i][j] == '(' ? 1 : -1;

                if (i > 0) {
                    if (change == 1) {
                        dp[i][j] |= dp[i - 1][j] << 1;
                    } else {
                        dp[i][j] |= dp[i - 1][j] >> 1;
                    }
                }

                if (j > 0) {
                    if (change == 1) {
                        dp[i][j] |= dp[i][j - 1] << 1;
                    } else {
                        dp[i][j] |= dp[i][j - 1] >> 1;
                    }
                }
            }
        }

        return dp[n - 1][m - 1].test(0);
    }
};