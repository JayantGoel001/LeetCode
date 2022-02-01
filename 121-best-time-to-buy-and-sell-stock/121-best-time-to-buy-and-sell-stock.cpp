class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int mini = INT_MAX;
        
        for(auto it : prices){
            mini = min(mini,it);
            maxi = max(maxi,it - mini);
        }
        return maxi;
    }
};