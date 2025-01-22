class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int columns = isWater[0].size();
        // Large value to represent uninitialized heights
        const int INF = rows * columns;

        // Initialize the cellHeights matrix with INF (unprocessed cells)
        vector<vector<int>> cellHeights(rows, vector<int>(columns, INF));

        // Set the height of water cells to 0
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                if (isWater[row][col]) {
                    cellHeights[row][col] = 0;  // Water cells have height 0
                }
            }
        }

        // Forward pass: updating heights based on top and left neighbors
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                // Initialize minimum neighbor distance
                int minNeighborDistance = INF;

                // Check the cell above
                int neighborRow = row - 1;
                int neighborCol = col;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }

                // Check the cell to the left
                neighborRow = row;
                neighborCol = col - 1;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }

                // Set the current cell's height as the minimum of its neighbors
                // + 1
                cellHeights[row][col] =
                    min(cellHeights[row][col], minNeighborDistance + 1);
            }
        }

        // Backward pass: updating heights based on bottom and right neighbors
        for (int row = rows - 1; row >= 0; row--) {
            for (int col = columns - 1; col >= 0; col--) {
                // Initialize minimum neighbor distance
                int minNeighborDistance = INF;

                // Check the cell below
                int neighborRow = row + 1;
                int neighborCol = col;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }

                // Check the cell to the right
                neighborRow = row;
                neighborCol = col + 1;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }

                // Set the current cell's height as the minimum of its neighbors
                // + 1
                cellHeights[row][col] =
                    min(cellHeights[row][col], minNeighborDistance + 1);
            }
        }

        return cellHeights;  // Return the calculated cell heights
    }

private:
    // Function to check if a cell is within grid bounds
    bool isValidCell(int row, int col, int rows, int columns) {
        return row >= 0 && col >= 0 && row < rows && col < columns;
    }
};