class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        
        return max(pos, neg);
    }
};