class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n+1];
        int c2 = 0;
        int c3 = 0;
        int c5 = 0;
        
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            dp[i] = min({2 * dp[c2],3 * dp[c3],5 * dp[c5]});
            if(dp[i] == 2 * dp[c2]){
                c2++;
            }
            if(dp[i] == 3 * dp[c3]){
                c3++;
            }
            if(dp[i] == 5 * dp[c5]){
                c5++;
            }
        }
        return dp[n-1];
    }
};