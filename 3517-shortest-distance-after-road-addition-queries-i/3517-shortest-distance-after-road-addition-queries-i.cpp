class Solution {
public:
    // Function to find the minimum distance from node 0 to node n-1
    int findMinDistance(vector<vector<int>> &adjList, int n) {
        vector<int> dp(n);
        dp[n - 1] = 0;  // Base case: distance to destination (n-1) is 0

        // Iterate from the second last node down to the first node
        for (int currentNode = n - 2; currentNode >= 0; currentNode--) {
            int minDistance = n;
            // Explore neighbors to find the minimum distance
            for (auto neighbor : adjList[currentNode]) {
                minDistance = min(minDistance, dp[neighbor] + 1);
            }
            dp[currentNode] = minDistance;  // Store the calculated distance for
                                            // the current node
        }
        return dp[0];
    }

    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>> &queries) {
        vector<int> answer;
        vector<vector<int>> adjList(n, vector<int>(0));

        // Initialize edges between consecutive nodes
        for (int i = 0; i < n - 1; i++) {
            adjList[i].push_back(i + 1);
        }

        // Process each query to add new edges
        for (auto &road : queries) {
            int u = road[0];
            int v = road[1];
            adjList[u].push_back(v);  // Add the directed edge from u to v

            // Calculate the minimum distance after adding the new edge
            answer.push_back(findMinDistance(adjList, n));
        }
        return answer;
    }
};