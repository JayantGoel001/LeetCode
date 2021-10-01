class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int minCoins[amount + 1];
        for(int i=0;i<=amount;i++){
            minCoins[i] = INT_MAX-1;
        }
        minCoins[0] = 0;
        int size = coins.size();
        for(int i = 0;i<size;i++){
            for(int j=coins[i];j<=amount;j++){
                minCoins[j] = min(minCoins[j],minCoins[j - coins[i]] + 1);
            }
        }
        if(minCoins[amount] == INT_MAX-1){
            return -1;
        }
        return minCoins[amount];
    }
};