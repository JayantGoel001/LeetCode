class Solution {
public:
    double average(vector<int>& salary) {
        double ans = 0;
        double mini = INT_MAX;
        double maxi = INT_MIN;
        
        for(auto it : salary){
            ans += it;
            mini = min(mini,(double)it);
            maxi = max(maxi,(double)it);
        }
        ans -= mini;
        ans -= maxi;
        
        return ans/(salary.size() - 2);
    }
};