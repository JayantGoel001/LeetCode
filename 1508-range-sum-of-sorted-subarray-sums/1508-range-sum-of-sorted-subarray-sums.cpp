class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mqueue;
        for (int i=0; i<n; i++)
            mqueue.push({nums[i], i+1});

        int ans = 0, mod = 1e9+7;
        for (int i=1; i<=right; i++) {
            auto p = mqueue.top();
            mqueue.pop();
            if (i >= left)
                ans = (ans + p.first) % mod;
            if (p.second < n) {
                p.first += nums[p.second++];
                mqueue.push(p);
            }
        }
        return ans;
    }
};