class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(4, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        for(int i=3;i<=n;i++) {
            dp[i%4] = dp[(i - 1) % 4] + dp[(i - 2) % 4] + dp[(i - 3) % 4];
        }

        return dp[n%4];
    }
};