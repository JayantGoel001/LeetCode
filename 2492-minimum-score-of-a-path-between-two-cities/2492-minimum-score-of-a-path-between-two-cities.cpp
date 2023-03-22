#define pii pair<int,int>
class Solution {
public:
    vector<vector<pii>> adj;
    int ans = INT_MAX;
    void dfs(int u, vector<bool> &vis){
        vis[u] = true;
        
        for(auto it : adj[u]){
            ans = min(ans, it.second);
            if(!vis[it.first]){
                dfs(it.first, vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        adj.resize(n + 1);
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<bool> vis(n + 1, false);
        dfs(1, vis);
        
        return ans;
    }
};