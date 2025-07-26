class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<int> bMin1(n + 1, INT_MAX), bMin2(n + 1, INT_MAX);
        for (const auto& pair : conflictingPairs) {
            int a = min(pair[0], pair[1]), b = max(pair[0], pair[1]);
            if (bMin1[a] > b) {
                bMin2[a] = bMin1[a];
                bMin1[a] = b;
            } else if (bMin2[a] > b) {
                bMin2[a] = b;
            }
        }
        long long res = 0;
        int ib1 = n, b2 = INT_MAX;
        vector<long long> delCount(n + 1, 0);
        for (int i = n; i >= 1; i--) {
            if (bMin1[ib1] > bMin1[i]) {
                b2 = min(b2, bMin1[ib1]);
                ib1 = i;
            } else {
                b2 = min(b2, bMin1[i]);
            }
            res += min(bMin1[ib1], n + 1) - i;
            delCount[ib1] +=
                min(min(b2, bMin2[ib1]), n + 1) - min(bMin1[ib1], n + 1);
        }
        return res + *max_element(delCount.begin(), delCount.end());
    }
};