class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();
        long long ans = 0;
        int k = k1 + k2;
        int maxDif = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            nums1[i] = abs(nums1[i] - nums2[i]);
            maxDif = max(maxDif, nums1[i]);
        }
        int l = 0, r = maxDif;
        auto check = [&](int mid) -> bool {
            long long sum = 0;
            for (int num : nums1) {
                sum += num > mid ? num - mid : 0;
            }
            return sum <= k;
        };
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid - 1;
                res = mid;
            } else {
                l = mid + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums1[i] > res) {
                k -= (nums1[i] - res);
            }
        }
        sort(nums1.begin(), nums1.end(), greater<int>());
        for (int num : nums1) {
            long long diff = res >= num ? num : res;
            if (k && diff) {
                diff--;
                k--;
            }
            ans += diff * diff;
        }
        return ans;
    }
};