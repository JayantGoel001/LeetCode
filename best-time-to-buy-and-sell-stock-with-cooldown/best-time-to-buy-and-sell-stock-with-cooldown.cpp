class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        
        int prev = 0;
        int curr = INT_MIN;
        
        int size = prices.size();
        for(int i=0;i<size;i++){
            int temp = maxi;
            curr = max(curr,prev - prices[i]);
            maxi = max(maxi,curr + prices[i]);
            prev = temp;
        }
        return maxi;
    }
};