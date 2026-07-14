class Solution {
    static constexpr int MOD = 1e9 + 7;

public:
    int subsequencePairCount(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> dp(m + 1, vector<int>(m + 1));
        dp[0][0] = 1;

        for (int num : nums) {
            vector<vector<int>> ndp(m + 1, vector<int>(m + 1));
            for (int j = 0; j <= m; j++) {
                int divisor1 = gcd(j, num);
                for (int k = 0; k <= m; k++) {
                    int val = dp[j][k];
                    if (val == 0) {
                        continue;
                    }
                    int divisor2 = gcd(k, num);
                    ndp[j][k] = (ndp[j][k] + val) % MOD;
                    ndp[divisor1][k] = (ndp[divisor1][k] + val) % MOD;
                    ndp[j][divisor2] = (ndp[j][divisor2] + val) % MOD;
                }
            }
            dp.swap(ndp);
        }

        int ans = 0;
        for (int j = 1; j <= m; j++) {
            ans = (ans + dp[j][j]) % MOD;
        }

        return ans;
    }
};