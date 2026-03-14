class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for(int i=1;i<nums.size();i++) {
            nums[i] += nums[i - 1];
        }

        for(int i=0;i<nums.size();i++) {
            if ((i > 0 ? nums[i - 1] : 0) + nums[i] == nums.back()) return i;
        }

        return -1;
    }
};