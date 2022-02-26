class Solution {
public:
    vector<vector<int>> dp;
    
    int LCS(string &text1, string &text2, int n, int m){
        if(n == 0 || m == 0){
            return 0;
        }
        if(dp[n][m] == -1){
            if(text1[n - 1] == text2[m - 1]){
                dp[n][m] = LCS(text1, text2, n - 1, m - 1) + 1;
            }else{
                dp[n][m] = max(LCS(text1, text2, n - 1, m),LCS(text1, text2, n, m - 1));
            }
        }
        return dp[n][m];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        dp.resize(n + 1,vector<int> (m + 1,-1));
        
        return LCS(text1, text2, n, m);
    }
};