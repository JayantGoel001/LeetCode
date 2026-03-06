class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN;
        int hold2 = INT_MIN;
        
        int maxi1 = 0;
        int maxi2 = 0;
        for(auto it : prices){
            maxi2 = max(maxi2,hold2 + it);
            hold2 = max(hold2,maxi1 - it);
            
            maxi1 = max(maxi1,hold1 + it);
            hold1 = max(hold1, - it);
        }
        return maxi2;
    }
};