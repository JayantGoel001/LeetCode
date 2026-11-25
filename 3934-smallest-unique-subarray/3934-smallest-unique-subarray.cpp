class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> sa(n), rank(nums.begin(), nums.end());
        vector<int> nextRank(n);

        iota(sa.begin(), sa.end(), 0);

        // Construct the sorted suffix array by doubling
        int maxRank = *max_element(nums.begin(), nums.end());
        vector<int> temp(n), cnt(std::max(n + 1, maxRank + 2));

        auto counting_sort = [&](auto get_key) {
            fill(cnt.begin(), cnt.end(), 0);

            for (int i : sa) {
                ++cnt[get_key(i)];
            }

            for (int i = 1; i <= maxRank + 1; ++i) {
                cnt[i] += cnt[i - 1];
            }

            for (int p = n - 1; p >= 0; --p) {
                int i = sa[p];
                temp[--cnt[get_key(i)]] = i;
            }

            sa.swap(temp);
        };

        for (int k = 1; k < n; k <<= 1) {
            auto get_rank = [&](int i) -> pair<int, int> {
                return {rank[i], i + k < n ? rank[i + k] : -1};
            };

            // Sort by the second key, then stably sort by the first key
            counting_sort([&](int i) { return get_rank(i).second + 1; });
            counting_sort([&](int i) { return get_rank(i).first + 1; });

            nextRank[sa[0]] = 0;

            // Assign ranks to the newly sorted suffixes
            for (int i = 1; i < n; ++i) {
                auto rx = get_rank(sa[i - 1]), ry = get_rank(sa[i]);
                nextRank[sa[i]] = nextRank[sa[i - 1]] + (rx != ry);
            }

            rank.swap(nextRank);
            maxRank = rank[sa.back()];

            // All n suffixes have distinct ranks, so sorting is complete
            if (maxRank == n - 1) {
                break;
            }
        }

        // Construct LCP using Kasai's algorithm
        vector<int> pos(n), lcp(n, 0);
        for (int i = 0; i < n; ++i) {
            pos[sa[i]] = i;
        }

        int h = 0;
        for (int i = 0; i < n; ++i) {
            if (pos[i] == 0) {
                h = 0;
                continue;
            }

            int j = sa[pos[i] - 1];
            while (i + h < n && j + h < n && nums[i + h] == nums[j + h]) {
                ++h;
            }

            lcp[pos[i]] = h;

            if (h > 0) {
                --h;
            }
        }

        int answer = n;
        for (int i = 0; i < n; ++i) {
            int next = (i + 1 < n ? lcp[i + 1] : 0);

            int need = std::max(lcp[i], next) + 1;
            if (sa[i] + need - 1 < n) {
                answer = std::min(answer, need);
            }
        }

        return answer;
    }
};