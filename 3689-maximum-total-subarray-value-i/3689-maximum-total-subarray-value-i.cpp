class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int m1 = INT_MAX, m2 = INT_MIN;
        for (int x : nums) {
            m1 = min(m1, x);
            m2 = max(m2, x);
        }
        return (long long)(m2 - m1) * k;
    }
};