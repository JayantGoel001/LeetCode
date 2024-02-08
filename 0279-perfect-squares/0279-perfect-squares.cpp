class Solution {
public:
    int getNOPS(int n,int *dp){
        if(n == 0){
            return 0;
        }else if(n > 0){
            if(dp[n]!=INT_MAX){
                return dp[n];
            }
            for(int i=1;i*i<=n;i++){
                dp[n] = min(dp[n],getNOPS(n-i*i,dp)+1);
            }
            return dp[n];
        }else{
            return INT_MAX-1;
        }
    }
    int numSquares(int n) {
        int dp[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = INT_MAX;
        }
        getNOPS(n,dp);
        return dp[n];
    }
};