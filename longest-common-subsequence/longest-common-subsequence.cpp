class Solution {
public:
    int LCS(string &text1, string &text2,int n,int m,int **dp){
        if(n==0 || m==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(text1[n-1] == text2[m-1]){
            dp[n][m] = LCS(text1,text2,n-1,m-1,dp) + 1;
        }else{
            dp[n][m] = max(LCS(text1,text2,n,m-1,dp),LCS(text1,text2,n-1,m,dp));
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string &text1, string &text2) {
        int n = text1.size();
        int m = text2.size();
        
        int **dp = new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = new int[m+1];
        }
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j] = -1;
            }
        }
        
        return LCS(text1,text2,n,m,dp);
    }
};