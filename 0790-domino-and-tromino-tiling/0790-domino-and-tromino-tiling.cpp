class Solution {
public:
    const int MOD = 1e9 + 7;
    int numTilings(int n) {
        
        vector<int> dp(4, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3;i<=n;i++) {
            dp[i % 4] = ((2 * dp[(i - 1) % 4]) % MOD + dp[(i - 3) % 4]) % MOD;
        }

        return dp[n % 4];
    }
};