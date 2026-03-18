#define pii pair<int,int>
class Solution {
public:
    int DFS(vector<vector<pii>> &adj, int u, vector<pii> &dist, vector<bool> &vis) {
        vis[u] = true;
        int totalRev = 0;
        for(auto it : adj[u]) {
            if (vis[it.first]) continue;

            dist[it.first] = {dist[u].first + 1, dist[u].second + it.second};
            totalRev += it.second;

            totalRev += DFS(adj, it.first, dist, vis);
        }

        return totalRev;
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pii>> adj(n);
        for(auto it: edges) {
            adj[it[0]].push_back({it[1], 0});
            adj[it[1]].push_back({it[0], 1});
        }

        vector<pii> dist(n, {0, 0});
        vector<bool> visited(n, false);
        int totalRev = DFS(adj, 0, dist, visited);

        vector<int> res;
        for(int i=0;i<n;i++) {
            cout << dist[i].first << " " << dist[i].second << "\n";
            res.push_back(dist[i].first - dist[i].second + totalRev - dist[i].second);
        }

        return res;
    }
};