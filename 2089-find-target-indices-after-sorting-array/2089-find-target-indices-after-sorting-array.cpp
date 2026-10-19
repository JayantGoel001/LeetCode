class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt1 = 0;  // Number of elements less than target
        int cnt2 = 0;  // Number of elements equal to target
        for (const int num : nums) {
            if (num < target) {
                ++cnt1;
            } else if (num == target) {
                ++cnt2;
            }
        }
        vector<int> res;  // Array of indices
        for (int i = cnt1; i < cnt1 + cnt2; ++i) {
            res.push_back(i);
        }
        return res;
    }
};