class Solution {
    vector<long long> getCosts(const vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> ops(n);

        multiset<int> left, right;
        long long sumL = 0, sumR = 0;

        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            if (left.empty() || v <= *left.rbegin()) {
                left.insert(v);
                sumL += v;
            } else {
                right.insert(v);
                sumR += v;
            }
            if (i >= x) {
                v = nums[i - x];
                auto it = left.find(v);
                if (it != left.end()) {
                    sumL -= v;
                    left.erase(it);
                } else {
                    it = right.find(v);
                    sumR -= v;
                    right.erase(it);
                }
            }
            if (left.size() > right.size() + 1) {
                auto it = prev(left.end());
                v = *it;
                right.insert(v);
                left.erase(it);
                sumL -= v;
                sumR += v;
            } else if (left.size() < right.size()) {
                auto it = right.begin();
                v = *it;
                left.insert(v);
                right.erase(it);
                sumL += v;
                sumR -= v;
            }
            if (i >= x - 1) {
                long long mid = *left.rbegin();
                long long leftCost = mid * (long long)left.size() - sumL;
                long long rightCost = sumR - mid * (long long)right.size();
                ops[i] = leftCost + rightCost;
            }
        }
        return ops;
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> ops = getCosts(nums, x);
        vector<long long> pre(n + 1, 0);
        vector<long long> cur(n + 1, LLONG_MAX);

        for (int j = 1; j <= k; ++j) {
            fill(cur.begin(), cur.end(), LLONG_MAX);
            for (int i = j * x; i <= n; ++i) {
                cur[i] = min(cur[i - 1], pre[i - x] + ops[i - 1]);
            }
            pre.swap(cur);
        }
        return pre[n];
    }
};