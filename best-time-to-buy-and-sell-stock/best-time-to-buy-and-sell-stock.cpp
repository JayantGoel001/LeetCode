class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        int n = prices.size();
        
        for(auto it : prices){
            mini = min(mini,it);
            
            maxi = max(maxi,it - mini);
        }
        return maxi == INT_MIN ? 0 : maxi;
    }
};