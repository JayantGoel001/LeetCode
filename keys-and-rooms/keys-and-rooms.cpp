class Solution {
public:
    void DFS(vector<vector<int>>& rooms,int u,vector<bool> &vis){
        vis[u] = true;
        for(auto it : rooms[u]){
            if(!vis[it]){
                DFS(rooms,it,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n,false);
        
        DFS(rooms,0,vis);
        bool res = true;
        for(auto it : vis){
            res &= it;
        }
        return res;
    }
};