class Solution {
public:
    int longestIdealString(string s, int k) {
        int N = size(s);
        vector<int> dp(26, 0);

        int res = 0;
        // Updating dp with the i-th character
        for (int i = 0; i < N; i++) {
            int curr = s[i] - 'a';
            int best = 0;
            for (int prev = 0; prev < 26; prev++) {
                if (abs(prev - curr) <= k) {
                    best = max(best, dp[prev]);
                }
            }

            // Appending s[i] to the previous longest ideal subsequence allowed
            dp[curr] = max(dp[curr], best + 1);
            res = max(res, dp[curr]);
        }
        return res;
    }
};