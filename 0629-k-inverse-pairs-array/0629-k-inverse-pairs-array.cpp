class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[2][1001] = { 1 };
        for (int N = 1; N <= n; ++N)
            for (int K = 0; K <= k; ++K) {
                dp[N % 2][K] = (dp[(N - 1) % 2][K] + (K > 0 ? dp[N % 2][K - 1] : 0)) % 1000000007;
                if (K >= N)
                    dp[N % 2][K] = (1000000007 + dp[N % 2][K] - dp[(N - 1) % 2][K - N]) % 1000000007;
            }
        return dp[n % 2][k];
    }
};