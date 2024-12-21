class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        if (n < 2) return 1;

        int componentCount = 0;
        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);

        // Build the graph and calculate in-degrees
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
            inDegree[node1]++;
            inDegree[node2]++;
        }

        // Convert values to long long to prevent overflow
        vector<long long> longValues(values.begin(), values.end());

        // Initialize the queue with nodes having in-degree of 1 (leaf nodes)
        queue<int> queue;
        for (int node = 0; node < n; node++) {
            if (inDegree[node] == 1) {
                queue.push(node);
            }
        }

        while (!queue.empty()) {
            int currentNode = queue.front();
            queue.pop();
            inDegree[currentNode]--;

            long long addValue = 0;

            // Check if the current node's value is divisible by k
            if (longValues[currentNode] % k == 0) {
                componentCount++;
            } else {
                addValue = longValues[currentNode];
            }

            // Propagate the value to the neighbor nodes
            for (int neighborNode : graph[currentNode]) {
                if (inDegree[neighborNode] == 0) {
                    continue;
                }

                inDegree[neighborNode]--;
                longValues[neighborNode] += addValue;

                // If the neighbor node's in-degree becomes 1, add it to the
                // queue
                if (inDegree[neighborNode] == 1) {
                    queue.push(neighborNode);
                }
            }
        }

        return componentCount;
    }
};