#define pii pair<int,int>
class Solution {
public:
    vector<int> vis;
    bool DFS(vector<vector<int>>& graph,int u,int color){
        vis[u] = color;
        
        for(auto it : graph[u]){
            if(vis[it] == -1){
                if(!DFS(graph, it, 1 - color)){
                    return false;
                }
            }else if(vis[it] == color){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vis.resize(n,-1);
        
        for(int i=0;i<n;i++){
            if(vis[i] == -1){
                if(!DFS(graph,i,0)){
                    return false;
                }
            }
        }
        return true;
    }
};