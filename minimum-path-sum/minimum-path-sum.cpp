class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dp[2][m+1];
        
        for(int i=0;i<2;i++){
            for(int j=0;j<=m;j++){
                dp[i][j] = INT_MAX;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i == 1 && j == 1){
                    dp[i%2][j] = grid[i-1][j-1];
                }else{
                    dp[i%2][j] = min(dp[(i-1)%2][j], dp[i%2][j-1]) + grid[i-1][j-1];
                }
            }
        }
        return dp[n%2][m];
    }
};