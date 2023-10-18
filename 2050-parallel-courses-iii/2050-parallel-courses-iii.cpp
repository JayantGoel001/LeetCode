class Solution {
public:
    unordered_map<int, vector<int>> graph;
    
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) { 
        unordered_map<int, vector<int>> graph;
        vector<int> indegree = vector(n, 0);

        for (vector<int>& edge: relations) {
            int x = edge[0] - 1;
            int y = edge[1] - 1;
            graph[x].push_back(y);
            indegree[y]++;
        }
        
        queue<int> queue;
        vector<int> maxTime = vector(n, 0);
        
        for (int node = 0; node < n; node++) {
            if (indegree[node] == 0) {
                queue.push(node);
                maxTime[node] = time[node];
            }
        }
        
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            for (int neighbor: graph[node]) {
                maxTime[neighbor] = max(maxTime[neighbor], maxTime[node] + time[neighbor]);
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    queue.push(neighbor);
                }
            }
        }
        
        int ans = 0;
        for (int node = 0; node < n; node++) {
            ans = max(ans, maxTime[node]);
        }
        
        return ans;
    }
};