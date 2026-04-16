class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> left(n), right(n);
        unordered_map<int, int> pos;
        for (int i = -n; i < n; i++) {
            if (i >= 0) {
                left[i] = pos[nums[i]];
            }
            pos[nums[(i + n) % n]] = i;
        }
        pos.clear();
        for (int i = 2 * n - 1; i >= 0; i--) {
            if (i < n) {
                right[i] = pos[nums[i]];
            }
            pos[nums[i % n]] = i;
        }
        int m = queries.size();
        for (int i = 0; i < m; i++) {
            int x = queries[i];
            queries[i] =
                (x - left[x] == n) ? -1 : min(x - left[x], right[x] - x);
        }
        return queries;
    }
};