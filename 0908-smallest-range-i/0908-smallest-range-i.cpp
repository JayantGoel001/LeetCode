class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        if(nums.size() == 1){
            return 0;
        }
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(auto it : nums){
            mini = min(mini, it);
            maxi = max(maxi, it);
        }
        
        return max(maxi - mini - 2 * k, 0);
    }
};