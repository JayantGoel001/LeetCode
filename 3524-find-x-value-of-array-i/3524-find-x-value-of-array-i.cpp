class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k);
        vector<long long> dp(k);  // Initial state: no elements have been
                                  // processed, so no non-empty subarray exists.

        for (int i = 0; i < n; i++) {
            vector<long long> ndp(k);  // Current-layer state (rolling array).

            ndp[nums[i] % k]++;

            for (int r = 0; r < k; r++) {
                ndp[(long long)r * nums[i] % k] += dp[r];
            }

            dp = move(ndp);  // Update the state.

            // Accumulate the answer.
            for (int r = 0; r < k; r++) {
                result[r] += dp[r];
            }
        }

        return result;
    }
};