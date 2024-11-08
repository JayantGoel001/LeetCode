class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorProduct = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorProduct = xorProduct ^ nums[i];
        }
        vector<int> ans(nums.size());

        int mask = (1 << maximumBit) - 1;

        for (int i = 0; i < nums.size(); i++) {
            ans[i] = xorProduct ^ mask;
            // remove last element
            xorProduct = xorProduct ^ nums[nums.size() - 1 - i];
        }

        return ans;
    }
};