class Solution {
private:
    // Helper function to find the root of a component
    int findParent(vector<int>& parent, int cellIndex) {
        if (parent[cellIndex] == cellIndex) {
            return cellIndex;
        }
        return parent[cellIndex] =
                   findParent(parent, parent[cellIndex]);  // Path compression
    }

    // Helper function to union two components
    void unionComponents(vector<int>& parent, vector<int>& componentSize,
                         vector<int>& totalFish, int cellIndex1,
                         int cellIndex2) {
        int root1 = findParent(parent, cellIndex1);
        int root2 = findParent(parent, cellIndex2);

        if (root1 != root2) {
            // Union by size to optimize tree height
            if (componentSize[root1] < componentSize[root2]) {
                swap(root1, root2);
            }
            parent[root2] = root1;
            componentSize[root1] += componentSize[root2];
            totalFish[root1] += totalFish[root2];
        }
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rowCount = grid.size(), columnCount = grid[0].size();
        int totalCells = rowCount * columnCount;

        // Initialize Union-Find structures
        vector<int> parent(totalCells);
        vector<int> componentSize(totalCells, 1);
        vector<int> totalFish(totalCells);

        // Set initial parent and fish count for each cell
        iota(parent.begin(), parent.end(), 0);
        for (int row = 0; row < rowCount; row++) {
            for (int column = 0; column < columnCount; column++) {
                int cellIndex = row * columnCount + column;
                totalFish[cellIndex] = grid[row][column];
            }
        }

        // Direction vectors for neighbors (right, left, down, up)
        vector<int> deltaRow{0, 0, 1, -1}, deltaColumn{1, -1, 0, 0};

        // Merge connected components
        for (int row = 0; row < rowCount; row++) {
            for (int column = 0; column < columnCount; column++) {
                if (grid[row][column] >
                    0) {  // Process only water cells with fish
                    int cellIndex = row * columnCount + column;
                    for (int direction = 0; direction < 4; direction++) {
                        int neighborRow = row + deltaRow[direction];
                        int neighborColumn = column + deltaColumn[direction];
                        if (neighborRow >= 0 && neighborRow < rowCount &&
                            neighborColumn >= 0 &&
                            neighborColumn < columnCount &&
                            grid[neighborRow][neighborColumn] > 0) {
                            int neighborIndex =
                                neighborRow * columnCount + neighborColumn;
                            unionComponents(parent, componentSize, totalFish,
                                            cellIndex, neighborIndex);
                        }
                    }
                }
            }
        }

        // Find the maximum fish in any component
        int maxFish = 0;
        for (int cellIndex = 0; cellIndex < totalCells; cellIndex++) {
            if (findParent(parent, cellIndex) ==
                cellIndex) {  // Check if cellIndex is a root
                maxFish = max(maxFish, totalFish[cellIndex]);
            }
        }
        return maxFish;
    }
};