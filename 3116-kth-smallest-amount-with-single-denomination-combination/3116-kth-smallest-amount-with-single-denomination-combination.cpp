class Solution {
public:
    using ll = long long;
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        vector<int> new_coins;
        for (int x : coins) {
            bool flag = true;
            for (int y : new_coins) {
                if (x % y == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                new_coins.push_back(x);
            }
        }
        coins = new_coins;

        int n = coins.size();
        int m = (1 << n);
        vector<int> bit_count(m);
        vector<ll> lcm(m, 1);
        ll l = k, r = 1ll * coins[0] * k + 1;

        for (int mask = 1; mask < m; mask++) {
            int pre_mask = mask & (mask - 1);
            int i = __builtin_ctz(mask);

            ll tmp = lcm[pre_mask] / gcd(lcm[pre_mask], coins[i]);
            if (tmp <= r / coins[i]) {
                lcm[mask] = tmp * coins[i];
            } else {
                lcm[mask] = r + 1;
            }
        }

        auto get = [&](ll x) -> ll {
            ll count = 0;
            for (int mask = 1; mask < m; mask++) {
                if (lcm[mask] > x) {
                    continue;
                }
                if (__builtin_popcount(mask) & 1) {
                    count += x / lcm[mask];
                } else {
                    count -= x / lcm[mask];
                }
            }
            return count;
        };

        while (l < r) {
            ll x = (l + r) >> 1;
            if (get(x) >= k) {
                r = x;
            } else {
                l = x + 1;
            }
        }
        return l;
    }
};