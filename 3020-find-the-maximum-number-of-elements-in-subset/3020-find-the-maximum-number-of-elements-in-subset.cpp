class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int num : nums) {
            cnt[num]++;
        }
        int ans = 0;
        // ans is at least the number of occurrences of 1, rounded down to an
        // odd number
        if (cnt[1] % 2 == 0) {
            ans = cnt[1] - 1;
        } else {
            ans = cnt[1];
        }
        cnt.erase(1);
        for (auto& [num, _] : cnt) {
            int res = 0;
            long long x = num;
            for (; cnt.contains(x) && cnt[x] > 1; x *= x) {
                res += 2;
            }
            ans = max(ans, res + (cnt.contains(x) ? 1 : -1));
        }
        return ans;
    }
};