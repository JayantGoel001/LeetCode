class Solution {
public:
    vector<bool> vis;
    
    void DFS(vector<vector<int>>& rooms,int u){
        vis[u] = true;
        
        for(auto it : rooms[u]){
            if(!vis[it]){
                DFS(rooms,it);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vis.resize(rooms.size(),false);
        
        DFS(rooms,0);
        
        bool res = true;
        for(auto it : vis){
            res &= it;
        }
        return res;
    }
};