class Solution {
public:
    short dp[2001][2001][2] = {}, max_val = 2002;
    short dfs(vector<int>& t, vector<int>& s, int i, int j, bool prev_t) {
        if (i >= t.size()) 
          return 0;
        int prev = prev_t ? i == 0 ? INT_MIN : t[i - 1] : s[j];
        j = upper_bound(begin(s) + j, end(s), prev) - begin(s);
        if (dp[i][j][prev_t] == 0) {
            dp[i][j][prev_t] = max_val;
            if (j < s.size())
                dp[i][j][prev_t] = dfs(t, s, i + 1, j, false) + 1;
            if (prev < t[i])
                dp[i][j][prev_t] = min(dp[i][j][prev_t], dfs(t, s, i + 1, j, true));
        }
        return dp[i][j][prev_t];
    }
    int makeArrayIncreasing(vector<int>& t, vector<int>& s) {
      sort(begin(s), end(s));
      auto res = dfs(t, s, 0, 0, true);
      return res >= max_val ? -1 : res;
    }
};