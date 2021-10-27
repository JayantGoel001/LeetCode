class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n <= 1){
            return n;
        }
        vector<int> dp(n+1,0);
        dp[1] = 1;
        int maxi = 1;
        for(int i=1;2*i<n;i++){
            dp[2 * i] = dp[i];
            dp[2 * i + 1] = dp[i] + dp[i+1];
            maxi = max({maxi,dp[2 * i],dp[2 * i + 1]});
        }
        return maxi;
    }
};