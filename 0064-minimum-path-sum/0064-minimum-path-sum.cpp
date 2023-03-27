class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                int x = min(i == 0? INT_MAX : grid[i - 1][j], j == 0 ? INT_MAX : grid[i][j - 1]);
                if(x != INT_MAX){
                    grid[i][j] += x;
                }
            }
        }
        return grid[n - 1][m - 1];
    }
};