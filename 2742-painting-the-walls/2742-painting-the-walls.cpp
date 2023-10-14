class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp = vector(n + 1, 0);
        vector<int> prevDp = vector(n + 1, (int) 1e9);
        prevDp[0] = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            dp = vector(n + 1, 0);
            for (int remain = 1; remain <= n; remain++) {
                int paint = cost[i] + prevDp[max(0, remain - 1 - time[i])];
                int dontPaint = prevDp[remain];
                dp[remain] = min(paint, dontPaint);
            }
            
            prevDp = dp;
        }
        
        return dp[n];
    }
};