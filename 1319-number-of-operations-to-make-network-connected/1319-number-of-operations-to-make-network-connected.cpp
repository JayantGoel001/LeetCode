class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    
    void DFS(int u){
        vis[u] = true;
        
        for(auto it : adj[u]){
            if(!vis[it]){
                DFS(it);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& con) {
        adj.resize(n);
        vis.resize(n,false);
        
        if(con.size() < n - 1){
            return -1;
        }
        
        for(auto it : con){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                DFS(i);
                count++;
            }
        }
        return count - 1;
    }
};