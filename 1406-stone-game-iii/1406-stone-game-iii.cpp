class Solution {
public:
    static inline string s[] = {"Bob", "Tie", "Alice"};
    string stoneGameIII(vector<int>& A) {
        int n = A.size();
        int dp[4] = {0, 0, 0, 0};

        for (int i = n - 1; i >= 0; i--) {
            int j = i & 3;

            dp[j] = A[i] - dp[(i + 1) & 3];
            if (i + 2 <= n)
                dp[j] = max(dp[j], A[i] + A[i + 1] - dp[(i + 2) & 3]);
            if (i + 3 <= n)
                dp[j] = max(dp[j], A[i] + A[i + 1] + A[i + 2] - dp[(i + 3) & 3]);
        }

        return s[(dp[0] > 0) - (dp[0] < 0) + 1];
    }
};