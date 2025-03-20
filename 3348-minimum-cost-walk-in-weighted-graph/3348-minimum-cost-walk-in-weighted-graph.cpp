class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        // Create the adjacency list of the graph
        vector<vector<pair<int, int>>> adjList(n);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<bool> visited(n, false);

        // Array to store the component ID of each node
        vector<int> components(n);
        vector<int> componentCost;

        int componentId = 0;

        // Perform DFS for each unvisited node to identify components and
        // calculate their costs
        for (int node = 0; node < n; node++) {
            // If the node hasn't been visited, it's a new component
            if (!visited[node]) {
                // Get the component cost and mark all nodes in the component
                componentCost.push_back(getComponentCost(
                    node, adjList, visited, components, componentId));
                // Increment the component ID for the next component
                componentId++;
            }
        }

        vector<int> answer;

        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];

            if (components[start] == components[end]) {
                // If they are in the same component, return the precomputed
                // cost for the component
                answer.push_back(componentCost[components[start]]);
            } else {
                // If they are in different components, return -1
                answer.push_back(-1);
            }
        }

        return answer;
    }

private:
    // Helper function to calculate the cost of a component using DFS
    int getComponentCost(int node, vector<vector<pair<int, int>>>& adjList,
                         vector<bool>& visited, vector<int>& components,
                         int componentId) {
        // Initialize the cost to the number that has only 1s in its
        // binary representation
        int currentCost = INT_MAX;

        // Mark the node as part of the current component
        components[node] = componentId;
        visited[node] = true;

        // Explore all neighbors of the current node
        for (auto& [neighbor, weight] : adjList[node]) {
            // Update the cost by performing a bitwise AND of the edge
            // weights
            currentCost &= weight;

            if (!visited[neighbor]) {
                // Recursively calculate the cost of the rest of the component
                // and accumulate it into currentCost
                currentCost &= getComponentCost(neighbor, adjList, visited,
                                                components, componentId);
            }
        }

        return currentCost;
    }
};