class Solution {
public:
    int nCr(int n,int r,int **dp){
        if(n==1 || 1==r){
            return 1;
        }
        if(dp[n][r] != -1){
            return dp[n][r];
        }
        dp[n][r] = nCr(n,r-1,dp) + nCr(n-1,r,dp);
        return dp[n][r];
    }
    
    int uniquePaths(int x, int y) {
        
        int **dp = new int*[x+1];
        for(int i=0;i<=x;i++){
            dp[i] = new int[y+1];
        }
        
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                dp[i][j] = -1;
            }
        }
        return nCr(x,y,dp);
    }
};