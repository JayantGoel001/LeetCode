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

        vector<int> dp(m + 1, 0);

        for(int j=1;j<=m;j++) {
            dp[j] = j;
        }

        for(int i=1;i<=n;i++) {
            int prev = dp[0];
            dp[0] = i;
            for(int j=1;j<=m;j++) {
                int temp = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev;
                } else {
                    dp[j] = 1 + min({prev, dp[j], dp[j - 1]});
                }
                prev = temp;
            }
        }

        return dp[m];
    }
};