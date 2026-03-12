class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int> dp(26, 0);

        int maxi = 0;
        for(int i=1;i<=s.size();i++) {
            dp[s[i-1] - 'a']++;
            if (i >= k) {
                maxi = max(maxi, dp[0] + dp[4] + dp[8] + dp['o' - 'a'] + dp['u' - 'a']);
                dp[s[i - k] - 'a']--;
            }
        }

        return maxi;
    }
};