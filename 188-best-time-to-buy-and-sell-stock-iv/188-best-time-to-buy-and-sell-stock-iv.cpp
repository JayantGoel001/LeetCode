class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        if (prices.size() <= k) {
            return greedy(prices);
        }
        // Max profit after k times of buys
        vector<int> buys(k + 1, INT_MIN);
        // Max profit after k times of sells
        vector<int> sells(k + 1, 0);
        for (auto &price : prices) {
            for (int i = 1; i <= k; i++) {
                buys[i] = max(buys[i], sells[i - 1] - price);
                sells[i] = max(sells[i], buys[i] + price);
            }
        }
        return sells[k];
    }
    
    int greedy(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
};