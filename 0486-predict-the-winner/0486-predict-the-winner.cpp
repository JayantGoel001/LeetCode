class Solution {
public:
    bool predictTheWinner(vector<int>& A) {
        int n = A.size();
        if (~n & 1) return true;

        vector<int> dp(n);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = A[i];
            for (int j = i + 1; j < n; j++)
                dp[j] = max(A[i] - dp[j], A[j] - dp[j - 1]);
        }

        return dp[n - 1] >= 0;
    }
};