class Solution {
public:
    int up(int m,int n,int **dp){
        if(m == 1){
            return 1;
        }else if(n == 1){
            return 1;
        }else{
            if(dp[m][n]==-1){
                dp[m][n] = up(m-1,n,dp) + up(m,n-1,dp);
            }
            return dp[m][n];
        }
    }
    int uniquePaths(int m, int n) {
        int **dp = new int*[m + 1];
        for(int i=0;i<=m;i++){
            dp[i] = new int[n + 1];
            for(int j=0;j<=n;j++){
                dp[i][j] = -1;
            }
        }
        return up(m,n,dp);
    }
};