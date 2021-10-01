class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = 0;
        int high = prices.size()-1;
        
        int maxi = 0;
        int mini = INT_MAX;
        for(int i=0;i<prices.size();i++){
            mini = min(mini,prices[i]);
            maxi = max(maxi, prices[i] - mini);
        }
        return maxi;
    }
};