class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        deque<pair<int, int>> know, share;
        know.emplace_back(1, 1);
        int know_cnt = 1, share_cnt = 0;
        for (int i = 2; i <= n; ++i) {
            if (!know.empty() && know[0].first == i - delay) {
                know_cnt = (know_cnt - know[0].second + mod) % mod;
                share_cnt = (share_cnt + know[0].second) % mod;
                share.push_back(know[0]);
                know.pop_front();
            }
            if (!share.empty() && share[0].first == i - forget) {
                share_cnt = (share_cnt - share[0].second + mod) % mod;
                share.pop_front();
            }
            if (!share.empty()) {
                know_cnt = (know_cnt + share_cnt) % mod;
                know.emplace_back(i, share_cnt);
            }
        }
        return (know_cnt + share_cnt) % mod;
    }

private:
    static constexpr int mod = 1000000007;
};