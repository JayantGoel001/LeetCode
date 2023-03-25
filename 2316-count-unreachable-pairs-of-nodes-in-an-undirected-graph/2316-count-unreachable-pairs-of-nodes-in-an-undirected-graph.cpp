#define ll long long
class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    ll dfs(int u){
        ll count = 1;
        vis[u] = true;
        
        for(auto it: adj[u]){
            if(!vis[it]){
                count += dfs(it);
            }
        }
        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        ll count = 0;
        adj.resize(n);
        vis.resize(n, false);
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int num = n;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ll x = dfs(i);
                
                count += x * (num - x);
                num -= x;
            }
        }
        return count;
    }
};