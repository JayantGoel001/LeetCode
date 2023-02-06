class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int x = 0;
        int y = 0;
        int z = 0;
        
        for(int i=0;i<n;i++){
            int maxz = 0;
            int maxy = 0;
            
            for(int j=0;j<n;j++){
                x += grid[i][j] > 0;
                
                maxz = max(maxz, grid[i][j]);
                maxy = max(maxy, grid[j][i]);
            }
            z += maxz;
            y += maxy;
        }
        return x + y + z;
    }
};