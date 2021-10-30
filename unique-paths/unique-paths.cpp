class Solution {
public:
    int getPaths(int m,int n,vector<vector<int>> &dp){
        if(m==1 || n == 1){
            return 1;
        }
        if(dp[m][n]==-1){
            dp[m][n] = getPaths(m-1,n,dp) + getPaths(m,n-1,dp);
        }
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        return getPaths(m,n,dp);
    }
};