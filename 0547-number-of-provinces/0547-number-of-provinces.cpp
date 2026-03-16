class Solution {
public:
    void DFS(vector<vector<int>> &adj, int u, vector<bool> &vis) {
        vis[u] = true;
        for(auto it : adj[u]) {
            if (vis[it]) continue;
            DFS(adj, it, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if (isConnected[i][j]) {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }

        int provines = 0;
        vector<bool> vis(n, false);
        for(int i=0;i<n;i++) {
            if (!vis[i]) {
                provines++;
                DFS(v, i, vis);
            }
        }

        return provines;
    }
};