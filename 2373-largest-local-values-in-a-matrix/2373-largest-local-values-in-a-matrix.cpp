class Solution {
public:
    int maax(vector<vector<int>> &grid, int x, int y){
        int maxi = 0;
        
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                maxi = max(maxi, grid[i][j]);
            }
        }
        
        return maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> res(grid.size() - 2, vector<int> (grid.size() - 2));
        
        for(int i=0;i<grid.size()-2;i++){
            for(int j=0;j<grid.size()-2;j++){
                res[i][j] = maax(grid, i, j);
            }
        }
        
        return res;
    }
};