#define pii pair<int,int>
class Solution {
public:
    int DFS(vector<vector<pii>> &adj, int u, vector<bool> &vis) {
        vis[u] = true;
        int cost = 0;

        for(auto it : adj[u]) {
            if (vis[it.first]) continue;

            cost += it.second + DFS(adj, it.first, vis);
        }

        return cost;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pii>> adj(n);
        for(auto it : connections) {
            adj[it[0]].push_back({it[1], 0});
            adj[it[1]].push_back({it[0], 1});
        }
        vector<bool> visited(n, false);
        return n - 1 - DFS(adj, 0, visited);
    }
};