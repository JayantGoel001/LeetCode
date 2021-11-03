class Solution {
public:
    int minOP(string &word1,string &word2,int n,int m,int **dp){
        if(n < 0 && m < 0){
            return 0;
        }
        if(n < 0){
            return m+1;
        }
        if(m < 0){
            return n+1;
        }
        if(dp[n][m] != INT_MAX){
            return dp[n][m];
        }
        if(word1[n] != word2[m]){
            dp[n][m] = 1 + min(minOP(word1,word2,n-1,m,dp),minOP(word1,word2,n,m-1,dp));
        }else{
            dp[n][m] = minOP(word1,word2,n-1,m-1,dp);
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        int **dp = new int*[n];
        for(int i=0;i<n;i++){
            dp[i] = new int[m];
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j] = INT_MAX;
            }
        }
        
        return minOP(word1,word2,n-1,m-1,dp);
    }
};