class Solution {
public:
    using ll = long long;

    struct State {
        int prev, curr, tight, lead;
        ll cnt, sum;
    };

    ll solve(ll num) {
        // if the number has fewer than 3 digits, the fluctuation value is 0
        if (num < 100) {
            return 0;
        }
        string s = to_string(num);
        int n = s.size();

        vector<State> currStates;
        // digit 10 indicates the invalid invalid state when there are leading
        // zeros
        currStates.push_back({10, 10, 1, 1, 1, 0});
        for (int pos = 0; pos < n; ++pos) {
            int limit = s[pos] - '0';
            ll cnt[2][2][11][11] = {0};
            ll sum[2][2][11][11] = {0};

            for (const auto& st : currStates) {
                int maxDigit = st.tight ? limit : 9;
                for (int digit = 0; digit <= maxDigit; ++digit) {
                    int newLead = st.lead && (digit == 0);
                    int newPrev = st.curr;
                    int newCurr = newLead ? 10 : digit;
                    int newTight = st.tight && (digit == maxDigit);

                    ll add = 0;
                    // calculate fluctuation only when there are three
                    // significant digits (both prev and curr are valid and not
                    // leading zeros)
                    if (!newLead && st.prev != 10 && st.curr != 10) {
                        if ((st.prev < st.curr && st.curr > digit) ||
                            (st.prev > st.curr && st.curr < digit)) {
                            add = st.cnt;
                        }
                    }

                    cnt[newTight][newLead][newPrev][newCurr] += st.cnt;
                    sum[newTight][newLead][newPrev][newCurr] += st.sum + add;
                }
            }

            // collect legal states
            vector<State> nextStates;
            for (int tight = 0; tight < 2; ++tight) {
                for (int lead = 0; lead < 2; ++lead) {
                    for (int prev = 0; prev <= 10; ++prev) {
                        for (int curr = 0; curr <= 10; ++curr) {
                            ll c = cnt[tight][lead][prev][curr];
                            ll s = sum[tight][lead][prev][curr];
                            // if the current state is valid, proceed to the
                            // next round of calculation
                            if (c != 0) {
                                nextStates.push_back(
                                    {prev, curr, tight, lead, c, s});
                            }
                        }
                    }
                }
            }

            currStates.swap(nextStates);
        }

        // sum of fluctuation values of all valid states
        ll ans = 0;
        for (const auto& st : currStates) {
            ans += st.sum;
        }
        return ans;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};