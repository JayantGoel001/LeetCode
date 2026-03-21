class Solution {
public:
    int longestCommonSubsequence(string &text1, string &text2, int n, int m, vector<vector<int>> &dp) {
        if (n == 0 || m == 0) return 0;
        if (dp[n][m] == -1) {
            if (text1[n - 1] == text2[m - 1]) {
                return dp[n][m] = 1 + longestCommonSubsequence(text1, text2, n - 1, m - 1, dp);
            } else {
                return dp[n][m] = max(longestCommonSubsequence(text1, text2, n - 1, m, dp), longestCommonSubsequence(text1, text2, n, m - 1, dp));
            }
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return longestCommonSubsequence(text1, text2, n, m, dp);
    }
};