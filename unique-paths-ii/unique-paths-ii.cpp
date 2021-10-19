class Solution {
public:
    int getUP(vector<vector<int>>& grid,int n,int m,int **dp){
        if(n<=0 || m<=0 || grid[n-1][m-1] == 1){
            dp[n][m] = 0;
            return dp[n][m];
        }
        if(n == 1 && m == 1){
            dp[n][m] = 1;
            return dp[n][m];
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        dp[n][m] = getUP(grid,n-1,m,dp) + getUP(grid,n,m-1,dp);
        return dp[n][m];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0]){
            return 0;
        }
        
        if(n == 1 &&  m == 1){
            return !grid[0][0];
        }
        
        int **dp = new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = new int[m+1];
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j] = -1;
            }
        }
        getUP(grid,n,m,dp);
        return dp[n][m]!=-1 ? dp[n][m] : 0;
    }
};