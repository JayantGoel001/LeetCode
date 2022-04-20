class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int res = 0, sz = nums.size();
        partial_sum(begin(nums), end(nums), begin(nums));
        for (int i = 0, j = 0, k = 0; i < sz - 2; ++i) {
            j = max(i + 1, j);
            while (j < sz - 1 && nums[j] < nums[i] * 2)
                ++j;
            k = max(j, k);
            while (k < sz - 1 && nums[k] - nums[i] <= nums[sz - 1] - nums[k])
                ++k;
            res = (res + k - j) % 1000000007;
        }
        return res;
    }
};