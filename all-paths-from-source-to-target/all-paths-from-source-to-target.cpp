class Solution {
public:
    vector<vector<int>> v;
    
    void getPaths(vector<vector<int>>& graph,int u,int n,vector<bool> &vis,vector<int> &path){
        if(u == n){
            path.push_back(u);
            v.push_back(path);
            path.pop_back();
        }else{
            vis[u] = true;
            path.push_back(u);
            for(auto it : graph[u]){
                if(!vis[it]){
                    getPaths(graph,it,n,vis,path);
                }
            }
            path.pop_back();
            vis[u] = false;
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<bool> vis(n,false);
        vector<int> path;
        getPaths(graph,0,n-1,vis,path);
        return v;
    }
};