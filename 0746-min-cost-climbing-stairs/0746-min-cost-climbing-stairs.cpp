class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, INT_MAX);
        dp[0] = 0;
        dp[1] = cost[0];

        for(int i=2;i<=cost.size();i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i - 1];
        }

        return min(dp[cost.size()], dp[cost.size() - 1]);
    }
};