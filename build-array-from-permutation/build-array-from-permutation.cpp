class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> v;
        for(auto it : nums){
            v.push_back(nums[it]);
        }
        return v;
    }
};