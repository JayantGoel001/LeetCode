class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minidx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxidx = max_element(nums.begin(), nums.end()) - nums.begin();
        int l = min(minidx,
                    maxidx);  // The smaller value in the most valuable index
        int r =
            max(minidx, maxidx);  // The bigger value in the most valuable index
        return min(
            {r + 1, n - l, l + 1 + n - r});  // Calculate the minimum number of
                                             // deletions in three cases
    }
};