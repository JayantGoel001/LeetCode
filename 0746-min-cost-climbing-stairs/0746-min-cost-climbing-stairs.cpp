class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(3, INT_MAX);
        dp[0] = 0;
        dp[1] = cost[0];

        for(int i=2;i<=cost.size();i++) {
            dp[i%3] = min(dp[(i - 1)%3], dp[(i - 2)%3]) + cost[i - 1];
        }

        return min(dp[cost.size() % 3], dp[(cost.size() - 1) % 3]);
    }
};