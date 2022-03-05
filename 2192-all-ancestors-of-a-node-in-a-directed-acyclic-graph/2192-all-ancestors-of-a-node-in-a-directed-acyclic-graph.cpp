class Solution {
public:
    vector<vector<int>> adj;
    
    void DFS(int u,vector<bool> &vis){
        vis[u] = true;
        
        for(auto it : adj[u]){
            if(!vis[it]){
                DFS(it,vis);
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        adj.resize(n);
        
        for(auto it : edges){
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<n;i++){
            vector<bool> vis(n,false);
            DFS(i,vis);
            for(int j=0;j<n;j++){
                if(i!=j && vis[j]){
                    ans[i].push_back(j);
                }
            }
        }
        return ans;
    }
};