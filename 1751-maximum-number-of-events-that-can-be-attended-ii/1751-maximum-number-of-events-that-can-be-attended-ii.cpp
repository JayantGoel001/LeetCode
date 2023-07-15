class Solution {
public:
    vector<vector<int>> dp;
int dfs(vector<vector<int>>& e, int i, int k) {
    if (k == 0 || i >= e.size())
        return 0;
    if (dp[i][k] != -1) 
        return dp[i][k];
    auto j = upper_bound(begin(e) + i, end(e), e[i][1], 
        [](int t, const vector<int> &v) {return v[0] > t;}) - begin(e);
    return dp[i][k] = max(e[i][2] + dfs(e, j, k - 1), dfs(e, i + 1, k));
}
int maxValue(vector<vector<int>>& events, int k) {
    dp = vector<vector<int>>(events.size(), vector<int>(k + 1, -1));
    sort(begin(events), end(events));
    return dfs(events, 0, k);
}
};