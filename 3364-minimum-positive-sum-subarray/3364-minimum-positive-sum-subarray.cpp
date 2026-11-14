class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size(), best = INT_MAX;
        vector<int> pre(n + 1);
        partial_sum(nums.begin(), nums.end(), pre.begin() + 1);
        multiset<int> starts;  // pre[i] for every start i that fits the end j
        for (int j = l; j <= n; ++j) {
            starts.insert(pre[j - l]);  // start j - l: length l
            if (j > r)
                starts.erase(starts.find(pre[j - r - 1]));  // start j - r - 1: length r + 1, too long
            auto it = starts.lower_bound(pre[j]);  // the largest pre[i] < pre[j] sits right before it
            if (it != starts.begin())
                best = min(best, pre[j] - *prev(it));
        }
        return best == INT_MAX ? -1 : best;
    }
};