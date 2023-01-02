class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> v(grid.size()-2, vector<int> (grid[0].size() - 2));
        
        for(int i=0;i<grid.size()-2;i++){
            for(int j=0;j<grid[0].size()-2;j++){
                
                int maxi = 0;
                for(int a = i;a<=i+2;a++){
                    for(int b=j;b<=j+2;b++){
                        maxi = max(maxi, grid[a][b]);
                    }
                }
                v[i][j] = maxi;
            }
        }
        return v;
    }
};