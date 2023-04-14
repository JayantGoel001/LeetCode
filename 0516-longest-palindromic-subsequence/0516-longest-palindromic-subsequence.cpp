class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(2,vector<int>(n,0));
        
        for(int i=n-1;i>=0;i--){
            dp[i%2][i] = 1;
            for(int j=i+1;j<n;j++){
                if(s[i] == s[j]){
                    dp[i%2][j] = dp[(i+1)%2][j-1] + 2;
                }else{
                    dp[i%2][j] = max(dp[(i+1)%2][j],dp[i%2][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};