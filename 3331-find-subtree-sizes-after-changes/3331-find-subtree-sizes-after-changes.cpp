
class Solution {
public:
    vector<int> ans;

    void dfs(int u, vector<vector<int>>& adj, string& s,
             vector<int>& p, vector<int>& last) {
        int c = s[u] - 'a', old = last[c];

        if (u && old != -1) p[u] = old;
        last[c] = u;

        for (int v : adj[u])
            dfs(v, adj, s, p, last);

        last[c] = old;
    }

    int calc(int u, vector<vector<int>>& tree) {
        ans[u] = 1;
        for (int v : tree[u])
            ans[u] += calc(v, tree);
        return ans[u];
    }

    vector<int> findSubtreeSizes(vector<int>& p, string s) {
        int n = p.size();
        vector<vector<int>> adj(n), tree(n);

        for (int i = 1; i < n; i++)
            adj[p[i]].push_back(i);

        vector<int> last(26, -1);
        dfs(0, adj, s, p, last);

        for (int i = 1; i < n; i++)
            tree[p[i]].push_back(i);

        ans.resize(n);
        calc(0, tree);
        return ans;
    }
};