class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        auto&& r = restrictions;
        // Add restriction (1, 0)
        r.push_back({1, 0});
        sort(r.begin(), r.end());

        // Add restriction (n, n-1)
        if (r.back()[0] != n) {
            r.push_back({n, n - 1});
        }

        int m = r.size();

        // Pass restrictions from left to right
        for (int i = 1; i < m; ++i) {
            r[i][1] = min(r[i][1], r[i - 1][1] + (r[i][0] - r[i - 1][0]));
        }
        // Pass restrictions from right to left
        for (int i = m - 2; i >= 0; --i) {
            r[i][1] = min(r[i][1], r[i + 1][1] + (r[i + 1][0] - r[i][0]));
        }

        int ans = 0;
        for (int i = 0; i < m - 1; ++i) {
            // Calculate the maximum height of the buildings between r[i][0] and
            // r[i][1]
            int best = ((r[i + 1][0] - r[i][0]) + r[i][1] + r[i + 1][1]) / 2;
            ans = max(ans, best);
        }

        return ans;
    }
};