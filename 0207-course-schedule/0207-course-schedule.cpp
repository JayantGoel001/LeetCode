class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<bool> res;
    
    bool DFS(int u){
        vis[u] = true;
        res[u] = true;
        
        for(auto it : adj[u]){
            if(!vis[it]){
                if(DFS(it)){
                    return true;
                }
            }else if(res[it]){
                return true;
            }
        }
        res[u] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        vis.resize(numCourses);
        res.resize(numCourses);
        
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i] && DFS(i)){
                return false;
            }
        }
        return true;
    }
};