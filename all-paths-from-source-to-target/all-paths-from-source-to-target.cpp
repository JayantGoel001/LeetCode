class Solution {
public:
    vector<vector<int>> v;
    
    void getPaths(vector<vector<int>>& graph,int u,vector<int> &path,vector<bool> &isVis,int n){
        
        if(u == n){
            path.push_back(u);
            v.push_back(path);
            path.pop_back();
        }else{
            isVis[u] = true;
            path.push_back(u);
            for(auto it : graph[u]){
                if(!isVis[it]){
                    getPaths(graph,it,path,isVis,n);            
                }
            }
            path.pop_back();
            isVis[u] = false;
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        vector<bool> isVis(n,false);
        getPaths(graph,0,path,isVis,n-1);
        return v;
    }
};