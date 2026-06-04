class Solution {
public:
    int totalWaviness(int num1, int num2) {
        using ll = long long;
        // calculate the sum of fluctuation values of all numbers in [0, num]
        auto solve = [&](ll num) -> ll {
            // if the number is less than 3, the fluctuation value is 0
            if (num < 100) {
                return 0;
            }
            string s = to_string(num);
            int n = s.size();

            // memoized search uses two independent arrays
            // memo_cnt[pos][x][y]: the number of valid filling schemes where
            // the current position is pos, and the previous two positions are
            // x, y
            ll memo_cnt[16][10][10];
            // memo_sum[pos][x][y]: the fluctuation value when the current
            // position is pos and the two left digits are x and y
            ll memo_sum[16][10][10];
            memset(memo_cnt, -1, sizeof(memo_cnt));
            memset(memo_sum, -1, sizeof(memo_sum));

            auto dfs = [&](this auto&& dfs, int pos, int prev, int curr,
                           bool isLimit, bool isLeading) -> pair<ll, ll> {
                // end position
                if (pos == n) {
                    return {1, 0};
                }
                // only use memoization when not limited by an upper bound and
                // not containing leading zeros
                if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                    if (memo_cnt[pos][prev][curr] != -1) {
                        return {memo_cnt[pos][prev][curr],
                                memo_sum[pos][prev][curr]};
                    }
                }

                // calculate the number of solutions and volatility value under
                // current conditions
                ll cnt = 0, sum = 0;
                int up = isLimit ? s[pos] - '0' : 9;
                for (int digit = 0; digit <= up; ++digit) {
                    bool newLeading = isLeading && (digit == 0);
                    // the previous number is updated to curr
                    int newPrev = curr;
                    // the current number is updated to digit
                    int newCurr = newLeading ? -1 : digit;
                    auto [subCnt, subSum] =
                        dfs(pos + 1, newPrev, newCurr, isLimit && (digit == up),
                            newLeading);
                    // only calculate the volatility value when there are no
                    // leading zeros
                    if (!newLeading && prev >= 0 && curr >= 0) {
                        // when the value is a peak or a trough, update the
                        // current fluctuation value
                        if ((prev < curr && curr > digit) ||
                            (prev > curr && curr < digit)) {
                            sum += subCnt;
                        }
                    }

                    cnt += subCnt;
                    sum += subSum;
                }

                if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                    // update the memoization array
                    memo_cnt[pos][prev][curr] = cnt;
                    memo_sum[pos][prev][curr] = sum;
                }

                return {cnt, sum};
            };

            auto [_, totalSum] = dfs(0, -1, -1, true, true);
            return totalSum;
        };

        return (int)(solve(num2) - solve(num1 - 1));
    }
};