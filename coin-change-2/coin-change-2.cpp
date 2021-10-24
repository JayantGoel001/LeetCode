class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount + 1];
        
        for(int i=0;i<=amount;i++){
            dp[i] = 0;
        }
        dp[0] = 1;
        int count = 0;
        int size = coins.size();
        for(int i=0;i<size;i++){
            for(int j=0;j<=amount-coins[i];j++){
                dp[j + coins[i]] += dp[j];
            }
        }
        return dp[amount];
    }
};