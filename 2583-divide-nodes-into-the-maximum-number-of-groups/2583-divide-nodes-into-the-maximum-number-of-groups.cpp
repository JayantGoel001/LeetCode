class Solution {
public:
    // Main function to calculate the maximum number of groups for the entire
    // graph
    int magnificentSets(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(n);
        vector<int> parent(n, -1);
        vector<int> depth(n, 0);

        // Build the adjacency list and apply Union-Find for each edge
        for (auto edge : edges) {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
            Union(edge[0] - 1, edge[1] - 1, parent, depth);
        }

        unordered_map<int, int> numOfGroupsForComponent;

        // For each node, calculate the maximum number of groups for its
        // component
        for (int node = 0; node < n; node++) {
            int numberOfGroups = getNumberOfGroups(adjList, node, n);
            if (numberOfGroups == -1) return -1;  // If invalid split, return -1
            int rootNode = find(node, parent);
            numOfGroupsForComponent[rootNode] =
                max(numOfGroupsForComponent[rootNode], numberOfGroups);
        }

        // Calculate the total number of groups across all components
        int totalNumberOfGroups = 0;
        for (auto [rootNode, numberOfGroups] : numOfGroupsForComponent) {
            totalNumberOfGroups += numberOfGroups;
        }
        return totalNumberOfGroups;
    }

private:
    // Find the root of the given node in the Union-Find structure
    int find(int node, vector<int> &parent) {
        while (parent[node] != -1) node = parent[node];
        return node;
    }

    // Union operation to merge two sets
    void Union(int node1, int node2, vector<int> &parent, vector<int> &depth) {
        node1 = find(node1, parent);
        node2 = find(node2, parent);

        // If both nodes already belong to the same set, no action needed
        if (node1 == node2) return;

        // Union by rank (depth) to keep the tree balanced
        if (depth[node1] < depth[node2]) swap(node1, node2);
        parent[node2] = node1;

        // If the depths are equal, increment the depth of the new root
        if (depth[node1] == depth[node2]) depth[node1]++;
    }

    // Function to calculate the number of groups for a given component starting
    // from srcNode
    int getNumberOfGroups(vector<vector<int>> &adjList, int srcNode, int n) {
        queue<int> nodesQueue;
        vector<int> layerSeen(n, -1);
        nodesQueue.push(srcNode);
        layerSeen[srcNode] = 0;
        int deepestLayer = 0;

        // Perform BFS to calculate the number of layers (groups)
        while (!nodesQueue.empty()) {
            int numOfNodesInLayer = nodesQueue.size();
            for (int i = 0; i < numOfNodesInLayer; i++) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();
                for (int neighbor : adjList[currentNode]) {
                    // If neighbor hasn't been visited, assign it to the next
                    // layer
                    if (layerSeen[neighbor] == -1) {
                        layerSeen[neighbor] = deepestLayer + 1;
                        nodesQueue.push(neighbor);
                    } else {
                        // If the neighbor is already in the same layer, return
                        // -1 (invalid partition)
                        if (layerSeen[neighbor] == deepestLayer) {
                            return -1;
                        }
                    }
                }
            }
            deepestLayer++;
        }
        return deepestLayer;
    }
};