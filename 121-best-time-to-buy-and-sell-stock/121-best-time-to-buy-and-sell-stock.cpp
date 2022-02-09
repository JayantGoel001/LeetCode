class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int mini = INT_MAX;
        
        for(auto price : prices){
            maxi = max(maxi,price - mini);
            mini = min(mini,price);
        }
        return maxi;
    }
};