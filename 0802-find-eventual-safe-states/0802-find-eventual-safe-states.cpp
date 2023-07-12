class Solution {
public:
    vector<int> vis;
    bool DFS(vector<vector<int>>& graph,int u){
        if(vis[u] > 0){
            return vis[u] == 2;
        }
        vis[u] = 1;
        
        for(auto it : graph[u]){
            if(vis[it] == 1 || !DFS(graph,it)){
                return false;
            }
        }
        vis[u] = 2;
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vis.resize(n,0);
        
        vector<int> v;
        for(int i=0;i<n;i++){
            if(DFS(graph,i)){
                v.push_back(i);
            }    
        }
        return v;
    }
};