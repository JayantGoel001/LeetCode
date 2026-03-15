class Solution {
public:
    void DFS(vector<vector<int>> &adj, int u, unordered_set<int> &vis) {
        vis.insert(u);
        for(auto it : adj[u]) {
            if (vis.find(it) == vis.end()) DFS(adj, it, vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<vector<int>> adj(rooms.size());
        for(int i=0;i<rooms.size();i++) {
            for(auto it : rooms[i]) adj[i].push_back(it);
        }

        unordered_set<int> visited;

        DFS(adj, 0, visited);

        return visited.size() == rooms.size();
    }
};