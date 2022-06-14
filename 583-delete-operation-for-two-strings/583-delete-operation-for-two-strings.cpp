class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int dp[2][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i == 0 || j == 0){
                    dp[i%2][j] = i + j;
                }else if(word1[i-1] == word2[j-1]){
                    dp[i%2][j] = dp[(i-1)%2][j-1];
                }else{
                    dp[i%2][j] = 1 + min(dp[(i-1)%2][j],dp[i%2][j-1]);
                }
            }
        }
        return dp[n%2][m];
    }
};