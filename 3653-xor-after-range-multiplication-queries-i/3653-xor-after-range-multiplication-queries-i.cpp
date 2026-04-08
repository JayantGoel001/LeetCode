class Solution {
    static const int mod = 1e9 + 7;

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for (auto q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int i = l; i <= r; i += k) {
                nums[i] = 1ll * nums[i] * v % mod;
            }
        }
        int res = 0;
        for (auto x : nums) {
            res ^= x;
        }
        return res;
    }
};