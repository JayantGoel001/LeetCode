class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            res ^= nums[i];
        }
        return res;
    }
};