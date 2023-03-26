class Solution {
public:
    vector<int> prev;
    int ans = -1;
    vector<bool> vis;
    void dfs(vector<int> &edges, int u, int i){
        prev[u] = i;
        vis[u] = true;
        
        if(edges[u] != -1){
            if(!vis[edges[u]]){
                dfs(edges, edges[u],i + 1);
            }else if(prev[edges[u]] != -1){
                ans = max(ans, i + 1 - prev[edges[u]]);
            }
        }
        prev[u] = -1;
    }
    int longestCycle(vector<int>& edges) {
        vis.resize(edges.size(), false);
        prev.resize(edges.size(), -1);
        
        for(int i=0;i<edges.size();i++){
            if(!vis[i]){
                dfs(edges, i, 0);
            }
        }
        return ans;
    }
    
};