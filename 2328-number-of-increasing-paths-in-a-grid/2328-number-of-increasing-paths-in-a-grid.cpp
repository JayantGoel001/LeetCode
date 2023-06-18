static int MOD=1e9+7;
static vector<int> dirs={0,1,0,-1,0};
class Solution {
public:
    vector<vector<long>> memo;
    long dp(vector<vector<int>>& grid,int i,int j) {
        long result=1;  // Contribution of current cell as an increasing sequence.
        if(memo[i][j]!=-1)  // Return the cached results if they exist.
            return memo[i][j];
        for(int d=0;d<4;d++) {  // Check all 4 directions.
            int x=i+dirs[d],y=j+dirs[d+1];
            if(x>=0&&y>=0&&x<grid.size()&&y<grid[0].size()&&grid[x][y]>grid[i][j])
                result=(result+dp(grid,x,y))%MOD;       // Add the total number of cells in the longest path for all directions.
        }
        return memo[i][j]=result;
    }
    int countPaths(vector<vector<int>>& grid) {
        long result=0;
        memo.resize(grid.size(),vector<long>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++)      // For each cell as a starting point calculate the number of increasing paths it can contribute.
            for(int j=0;j<grid[0].size();j++)
                result=(result+dp(grid,i,j))%MOD;
        return result;
    }
};