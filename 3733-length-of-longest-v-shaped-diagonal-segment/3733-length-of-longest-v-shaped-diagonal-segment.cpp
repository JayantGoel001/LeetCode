class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        int memo[m][n][4][2];
        memset(memo, -1, sizeof(memo));

        function<int(int, int, int, bool, int)> dfs =
            [&](int cx, int cy, int direction, bool turn, int target) -> int {
            int nx = cx + dirs[direction][0];
            int ny = cy + dirs[direction][1];
            /* If it goes beyond the boundary or the next node's value is not
             * the target value, then return */
            if (nx < 0 || ny < 0 || nx >= m || ny >= n ||
                grid[nx][ny] != target) {
                return 0;
            }
            if (memo[nx][ny][direction][turn] != -1) {
                return memo[nx][ny][direction][turn];
            }

            /* Continue walking in the original direction. */
            int maxStep = dfs(nx, ny, direction, turn, 2 - target);
            if (turn) {
                /* Clockwise rotate 90 degrees turn */
                maxStep = fmax(maxStep, dfs(nx, ny, (direction + 1) % 4, false,
                                            2 - target));
            }
            memo[nx][ny][direction][turn] = maxStep + 1;
            return maxStep + 1;
        };

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int direction = 0; direction < 4; ++direction) {
                        res = fmax(res, dfs(i, j, direction, true, 2) + 1);
                    }
                }
            }
        }

        return res;
    }
};