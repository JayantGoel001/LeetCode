class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;

        for (auto& edge : adjacentPairs) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int root = 0;
        for (auto& pair : graph) {
            if (pair.second.size() == 1) {
                root = pair.first;
                break;
            }
        }
        
        int curr = root;
        vector<int> ans = {root};
        int prev = INT_MAX;
        
        while (ans.size() < graph.size()) {
            for (int neighbor : graph[curr]) {
                if (neighbor != prev) {
                    ans.push_back(neighbor);
                    prev = curr;
                    curr = neighbor;
                    break;
                }
            }
        }

        return ans;
    }
};