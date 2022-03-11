class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n);
        size_t res = 0, first_max = 0, second_max = 0;
        unordered_set<int> adj;
        for (auto r : roads) {
            ++cnt[r[0]];
            ++cnt[r[1]];
            adj.insert((min(r[0], r[1]) << 16) + max(r[0], r[1]));
        }
        int i_max = max_element(begin(cnt), end(cnt)) - begin(cnt);
        int cnt_max = count(begin(cnt), end(cnt), cnt[i_max]);
        if (cnt_max == 1) {
            for (auto j = 0; j < n; ++j)
                if (i_max != j)
                    res = max(res, cnt[i_max] + cnt[j] - adj.count((min(i_max, j) << 16) + max(i_max, j)));
        }
        else {
            int roads_between_max = count_if(begin(roads), end(roads), [&](vector<int>&r) {
                return cnt[r[0]] == cnt[i_max] && cnt[r[1]] == cnt[i_max];
            });
            res = 2 * cnt[i_max] - (cnt_max * (cnt_max - 1) / 2 > roads_between_max ? 0 : 1);
        }
        return res;
    }
};