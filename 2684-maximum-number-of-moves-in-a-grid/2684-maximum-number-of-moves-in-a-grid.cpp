class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();

        vector<vector<int>> dp(M, vector<int>(N, 0));
        // Cells in the first column will have the moves as 1.
        // This is required to ensure we have a way if the cell reachable or not
        // from the first column.
        for (int i = 0; i < M; i++) {
            dp[i][0] = 1;
        }

        int maxMoves = 0;
        for (int j = 1; j < N; j++) {
            for (int i = 0; i < M; i++) {
                // Check all the three next possible cells
                // Check if the next cell is greater than the previous one
                // Check if the previous cell was reachable, if the value is > 0
                if (grid[i][j] > grid[i][j - 1] && dp[i][j - 1] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
                }
                if (i - 1 >= 0 && grid[i][j] > grid[i - 1][j - 1] &&
                    dp[i - 1][j - 1] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                if (i + 1 < M && grid[i][j] > grid[i + 1][j - 1] &&
                    dp[i + 1][j - 1] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
                }

                maxMoves = max(maxMoves, dp[i][j] - 1);
            }
        }

        return maxMoves;
    }
};