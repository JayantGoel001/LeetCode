class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n + 1, 0);
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if (i == 1 && j == 1) dp[j] = 1;
                else dp[j] += dp[j - 1];
            }
        }
        return dp[n];
    }
};