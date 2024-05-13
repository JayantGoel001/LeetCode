class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            if(grid[i][0] == 0){
                for(int j=0;j<grid[i].size();j++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        int p = 1;
        int res = 0;
        for(int j=grid[0].size() - 1;j >= 0;j--){
            int count = 0;
            for(int i=0;i<grid.size();i++){
                count += grid[i][j];
            }
            res += max(count, (int)grid.size() - count) * p;
            p <<= 1;
        }
        return res;
    }
};