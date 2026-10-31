class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1'000'000'007;
        int m = grid.size(), n = grid[0].size();

        vector<array<long long, 2>> f(n, {0, 0});
        f[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    if (grid[i - 1][j] == 0) {
                        f[j][0] = (f[j][0] + f[j][1]) % MOD;
                    } else {
                        f[j][0] = f[j][1];
                    }
                }

                if (j > 0) {
                    if (grid[i][j - 1] == 0) {
                        f[j][1] = (f[j - 1][0] + f[j - 1][1]) % MOD;
                    } else {
                        f[j][1] = f[j - 1][0];
                    }
                }
            }
        }

        return (f[n - 1][0] + f[n - 1][1]) % MOD;
    }
};