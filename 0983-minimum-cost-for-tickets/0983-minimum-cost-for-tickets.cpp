class Solution {
public:
    vector<int> dp;
    vector<int> dur;
    
    int findMin(int x, vector<int> &days, vector<int> &costs){
        if(x == days.size()){
            return 0;
        }
        if(dp[x] == INT_MAX){
            int i = x;
            for(int k=0;k<3;k++){
                while(i < days.size() && days[x] + dur[k] > days[i]){
                    i++;
                }
                dp[x] = min(dp[x], findMin(i, days, costs) + costs[k]);
            }
        }
        return dp[x];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(), INT_MAX);
        dur.push_back(1);
        dur.push_back(7);
        dur.push_back(30);
        return findMin(0, days, costs);
    }
};