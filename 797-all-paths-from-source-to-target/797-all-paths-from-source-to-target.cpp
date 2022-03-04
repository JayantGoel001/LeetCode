class Solution {
public:
    vector<vector<int>> v;
    vector<bool> vis;
    int n;
    void generateAllPaths(vector<vector<int>>& graph,int u,vector<int> &_v){
        if(u == n - 1){
            v.push_back(_v);
            return;
        }
        
        vis[u] = true;
        for(auto it : graph[u]){
            if(!vis[it]){
                _v.push_back(it);
                generateAllPaths(graph,it,_v);
                _v.pop_back();
            }
        }
        vis[u] = false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vis.resize(graph.size(),false);
        n = graph.size();
        vector<int> _v;
        _v.push_back(0);
        
        generateAllPaths(graph,0,_v);
        return v;
    }
};