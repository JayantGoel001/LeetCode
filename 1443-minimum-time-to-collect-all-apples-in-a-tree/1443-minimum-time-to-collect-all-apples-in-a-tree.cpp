class Solution {
public:
    int DFS(vector<vector<int>> &adj, vector<bool>& hasApple, int u, int parent){
        int total = 0;
        
        for(auto it : adj[u]){
            if(it == parent){
                continue;
            }
            int count = DFS(adj, hasApple, it, u);
            
            if(count || hasApple[it]){
                total += count + 2;
            }
        }
        return total;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        return DFS(adj, hasApple, 0, -1);
    }
};