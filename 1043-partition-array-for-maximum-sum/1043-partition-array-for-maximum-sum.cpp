class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int N = arr.size();
        int K = k + 1;

        int dp[k + 1];
        memset(dp, 0, sizeof(dp));

        for (int start = N - 1; start >= 0; start--) {
            int currMax = 0;
            int end = min(N, start + k);
            
            for (int i = start; i < end; i++) {
                currMax = max(currMax, arr[i]);
                dp[start % K] = max(dp[start % K], dp[(i + 1) % K] + currMax * (i - start + 1));
            }
        }
        return dp[0];
    }
};