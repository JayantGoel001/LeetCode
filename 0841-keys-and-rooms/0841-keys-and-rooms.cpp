class Solution {
public:
    void DFS(vector<vector<int>> &adj, int u, vector<bool> &vis) {
        vis[u] = true;
        for(auto it : adj[u]) {
            if (!vis[it]) DFS(adj, it, vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<vector<int>> adj(rooms.size());
        for(int i=0;i<rooms.size();i++) {
            for(auto it : rooms[i]) adj[i].push_back(it);
        }

        vector<bool> visited(rooms.size(), false);

        DFS(adj, 0, visited);

        for(int i=0;i<rooms.size();i++) {
            if (!visited[i]) return false;
        }

        return true;
    }
};