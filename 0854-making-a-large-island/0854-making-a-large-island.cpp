class DisjointSet {
public:
    vector<int> parent;
    vector<int> islandSize;

    // Constructor to initialize DSU with `n` elements
    DisjointSet(int n) {
        parent.resize(n);
        islandSize.resize(n);
        for (int node = 0; node < n; node++) {
            // Each node is its own parent initially with size 1
            parent[node] = node;
            islandSize[node] = 1;
        }
    }

    // Function to find the root of a node with path compression
    int findRoot(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findRoot(parent[node]);
    }

    // Function to union two sets based on size
    void unionNodes(int nodeA, int nodeB) {
        int rootA = findRoot(nodeA);
        int rootB = findRoot(nodeB);

        // Already in the same set
        if (rootA == rootB) return;

        // Union by size: Attach the smaller island to the larger one
        if (islandSize[rootA] < islandSize[rootB]) {
            // Attach rootA to rootB
            parent[rootA] = rootB;
            // Update size of rootB's island
            islandSize[rootB] += islandSize[rootA];
        } else {
            // Attach rootB to rootA
            parent[rootB] = rootA;
            // Update size of rootA's island
            islandSize[rootA] += islandSize[rootB];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();

        // Initialize DSU for the entire grid
        DisjointSet ds(rows * columns);

        // Direction vectors for traversing up, down, left, and right
        vector<int> rowDirections = {1, -1, 0, 0};
        vector<int> columnDirections = {0, 0, 1, -1};

        // Step 1: Union adjacent `1`s in the grid
        for (int currentRow = 0; currentRow < rows; currentRow++) {
            for (int currentColumn = 0; currentColumn < columns;
                 currentColumn++) {
                if (grid[currentRow][currentColumn] == 1) {
                    // Flatten 2D index to 1D
                    int currentNode = (columns * currentRow) + currentColumn;

                    for (int direction = 0; direction < 4; direction++) {
                        int neighborRow = currentRow + rowDirections[direction];
                        int neighborColumn =
                            currentColumn + columnDirections[direction];

                        // Check bounds and ensure the neighbor is also `1`
                        if (neighborRow >= 0 && neighborRow < rows &&
                            neighborColumn >= 0 && neighborColumn < columns &&
                            grid[neighborRow][neighborColumn] == 1) {
                            int neighborNode =
                                columns * neighborRow + neighborColumn;
                            ds.unionNodes(currentNode, neighborNode);
                        }
                    }
                }
            }
        }

        // Step 2: Calculate the maximum possible island size
        int maxIslandSize = 0;
        // Flag to check if there are any zeros in the grid
        bool hasZero = false;
        // To store unique roots for a `0`'s neighbors
        unordered_set<int> uniqueRoots;

        for (int currentRow = 0; currentRow < rows; currentRow++) {
            for (int currentColumn = 0; currentColumn < columns;
                 currentColumn++) {
                if (grid[currentRow][currentColumn] == 0) {
                    hasZero = true;
                    // Start with the flipped `0`
                    int currentIslandSize = 1;

                    for (int direction = 0; direction < 4; direction++) {
                        int neighborRow = currentRow + rowDirections[direction];
                        int neighborColumn =
                            currentColumn + columnDirections[direction];

                        // Check bounds and ensure the neighbor is `1`
                        if (neighborRow >= 0 && neighborRow < rows &&
                            neighborColumn >= 0 && neighborColumn < columns &&
                            grid[neighborRow][neighborColumn] == 1) {
                            int neighborNode =
                                columns * neighborRow + neighborColumn;
                            int root = ds.findRoot(neighborNode);
                            uniqueRoots.insert(root);
                        }
                    }

                    // Sum up the sizes of unique neighboring islands
                    for (int root : uniqueRoots) {
                        currentIslandSize += ds.islandSize[root];
                    }

                    // Clear the set for the next `0`
                    uniqueRoots.clear();

                    // Update the result with the largest island size found
                    maxIslandSize = max(maxIslandSize, currentIslandSize);
                }
            }
        }

        // If there are no zeros, the largest island is the entire grid
        if (!hasZero) return rows * columns;

        return maxIslandSize;
    }
};