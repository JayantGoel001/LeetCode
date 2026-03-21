class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        for (int i0 = x, i1 = x + k - 1; i0 < i1; ++i0, --i1) {
            for (int j = y; j < y + k; ++j) {
                swap(grid[i0][j], grid[i1][j]);
            }
        }
        return grid;
    }
};