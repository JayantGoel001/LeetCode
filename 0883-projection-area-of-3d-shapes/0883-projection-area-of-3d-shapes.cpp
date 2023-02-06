class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int x = 0;
        int y = 0;
        int z = 0;
        
        for(int i=0;i<n;i++){
            int maxi = 0;
            for(int j=0;j<n;j++){
                x += grid[i][j] > 0;
                maxi = max(maxi, grid[i][j]);
            }
            z += maxi;
        }
        for(int j=0;j<n;j++){
            int maxi = 0;
            for(int i=0;i<n;i++){
                maxi = max(maxi, grid[i][j]);
            }
            y += maxi;
        }
        return x + y + z;
    }
};