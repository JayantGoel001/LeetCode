class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        long long dp[200001] = {};
        for (int i = q.size() - 1; i >= 0; --i)
            dp[i] = max(q[i][0] + dp[q[i][1] + i + 1], dp[i + 1]);
        return dp[0];
    }
};