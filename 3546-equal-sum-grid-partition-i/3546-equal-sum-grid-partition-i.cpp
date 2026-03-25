class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        
        for (auto &row : grid)
            for (int x : row)
                total += x;
        
        if (total % 2) return false;
        
        long long target = total / 2, sum = 0;
        
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++)
                sum += grid[i][j];
            if (sum == target) return true;
        }
        
        sum = 0;
        
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++)
                sum += grid[i][j];
            if (sum == target) return true;
        }
        
        return false;
    }
};