class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int maxi = 0;
        int hold = INT_MIN;
        int size = prices.size();
        
        for(int i=0;i<size;i++){
            hold = max(hold,maxi - prices[i]);
            maxi = max(maxi,prices[i] + hold - fee);
        }
        return maxi;
    }
};