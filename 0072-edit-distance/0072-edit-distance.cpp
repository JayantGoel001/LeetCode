class Solution {
    int minDistance(string &word1, string &word2, int n, int m, vector<vector<int>> &dp) {
        if (n == 0) return m;
        if (m == 0) return n;
        if (dp[n][m] == -1) {
            if (word1[n - 1] == word2[m - 1]) {
                dp[n][m] = minDistance(word1, word2, n - 1, m - 1, dp);
            } else {
                dp[n][m] = 1 + min(
                    {
                        minDistance(word1, word2, n - 1, m - 1, dp),
                        minDistance(word1, word2, n, m - 1, dp),
                        minDistance(word1, word2, n - 1, m, dp)
                    }
                );
            }
        }
        return dp[n][m];
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return minDistance(word1, word2, n, m, dp);
    }
};