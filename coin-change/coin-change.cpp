class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        
        for(int i=0;i<=amount;i++){
            dp[i] = INT_MAX - 1;
        }
        dp[0] = 0;
        int size = coins.size();
        for(int i=0;i<size;i++){
            for(int j=0;j<=amount-coins[i];j++){
                dp[j + coins[i]] = min(dp[j + coins[i]],dp[j] + 1);
            }
        }
        return dp[amount]==INT_MAX-1? -1 : dp[amount];
    }
};