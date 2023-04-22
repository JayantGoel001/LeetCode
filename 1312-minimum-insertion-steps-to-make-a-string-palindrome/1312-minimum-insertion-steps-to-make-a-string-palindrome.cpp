class Solution {
public:
    int lcs(string &s1, string &s2,int n, int m, vector<vector<int>> &dp){
        if(n == 0 || m == 0){
            return 0;
        }
        if(dp[n][m] == -1){
            if(s1[n - 1] == s2[m - 1]){
                dp[n][m] = 1 + lcs(s1,s2,n-1,m-1, dp);
            }else{
                dp[n][m] = max(lcs(s1,s2,n-1,m,dp), lcs(s1,s2,n,m-1,dp));
            }
        }
        return dp[n][m];
    }
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size() + 1, vector<int> (s.size() + 1, -1));
        string rev = "";
        for(int i = s.size() - 1;i >= 0;i--){
            rev += s[i];
        }
        return s.size() - lcs(s, rev, s.size(), s.size(), dp);
    }
};