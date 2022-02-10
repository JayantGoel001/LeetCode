class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long maxi = INT_MIN;
        long long sum = 0;
        
        for(auto it : milestones){
            maxi = max(maxi,(long long)it);
            sum += it;
        }
        long long left = sum - maxi;
        return min(sum,2 * left + 1);
    }
};