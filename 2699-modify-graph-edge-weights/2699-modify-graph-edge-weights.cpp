class Solution {
public:
    const int INF = 2e9;

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges,
                                           int source, int destination,
                                           int target) {
        vector<vector<pair<int, int>>> graph(n);

        // Step 1: Build the graph, excluding edges with -1 weights
        for (const auto& edge : edges) {
            if (edge[2] != -1) {
                graph[edge[0]].emplace_back(edge[1], edge[2]);
                graph[edge[1]].emplace_back(edge[0], edge[2]);
            }
        }

        // Step 2: Compute the initial shortest distance from source to
        // destination
        int currentShortestDistance =
            runDijkstra(n, source, destination, graph);
        if (currentShortestDistance < target) {
            return vector<vector<int>>();
        }

        bool matchesTarget = (currentShortestDistance == target);

        // Step 3: Iterate through each edge to adjust its weight if necessary
        for (auto& edge : edges) {
            if (edge[2] != -1)
                continue;  // Skip edges with already known weights

            // Set edge weight to a large value if current distance matches
            // target, else set to 1
            edge[2] = matchesTarget ? INF : 1;
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);

            // Step 4: If current shortest distance does not match target
            if (!matchesTarget) {
                // Compute the new shortest distance with the updated edge
                // weight
                int newDistance = runDijkstra(n, source, destination, graph);
                // If the new distance is within the target range, update edge
                // weight to match target
                if (newDistance <= target) {
                    matchesTarget = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        // Return modified edges if the target distance is achieved, otherwise
        // return an empty result
        return matchesTarget ? edges : vector<vector<int>>();
    }

private:
    int runDijkstra(int n, int source, int destination,
                    const vector<vector<pair<int, int>>>& graph) {
        vector<int> minDistance(n, INF);
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            minHeap;

        minDistance[source] = 0;
        minHeap.emplace(0, source);

        while (!minHeap.empty()) {
            auto [d, u] = minHeap.top();
            minHeap.pop();

            if (d > minDistance[u]) continue;

            for (const auto& [v, weight] : graph[u]) {
                if (d + weight < minDistance[v]) {
                    minDistance[v] = d + weight;
                    minHeap.emplace(minDistance[v], v);
                }
            }
        }

        return minDistance[destination];
    }
};