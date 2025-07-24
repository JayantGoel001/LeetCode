class Solution {
public:
    int calc(int part1, int part2, int part3) {
        return max(part1, max(part2, part3)) - min(part1, min(part2, part3));
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), cnt = 0;
        vector<int> sum(n), in(n), out(n);
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        function<void(int, int)> dfs = [&](int x, int fa) {
            in[x] = cnt++;
            sum[x] = nums[x];
            for (auto& y : adj[x]) {
                if (y == fa) {
                    continue;
                }
                dfs(y, x);
                sum[x] ^= sum[y];
            }
            out[x] = cnt;
        };

        dfs(0, -1);
        int res = INT_MAX;
        for (int u = 1; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (in[v] > in[u] && in[v] < out[u]) {
                    res = min(res,
                              calc(sum[0] ^ sum[u], sum[u] ^ sum[v], sum[v]));
                } else if (in[u] > in[v] && in[u] < out[v]) {
                    res = min(res,
                              calc(sum[0] ^ sum[v], sum[v] ^ sum[u], sum[u]));
                } else {
                    res = min(res,
                              calc(sum[0] ^ sum[u] ^ sum[v], sum[u], sum[v]));
                }
            }
        }
        return res;
    }
};