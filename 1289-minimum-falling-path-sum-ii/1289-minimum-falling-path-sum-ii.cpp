class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // Minimum and Second Minimum Column Index
        int nextMin1C = -1;
        int nextMin2C = -1;

        // Minimum and Second Minimum Value
        int nextMin1 = -1;
        int nextMin2 = -1;

        // Find the minimum and second minimum from the last row
        for (int col = 0; col < grid.size(); col++) {
            if (nextMin1 == -1 || grid[grid.size() - 1][col] <= nextMin1) {
                nextMin2 = nextMin1;
                nextMin2C = nextMin1C;
                nextMin1 = grid[grid.size() - 1][col];
                nextMin1C = col;
            } else if (nextMin2 == -1 || grid[grid.size() - 1][col] <= nextMin2) {
                nextMin2 = grid[grid.size() - 1][col];
                nextMin2C = col;
            }
        }

        // Fill the recursive cases
        for (int row = grid.size() - 2; row >= 0; row--) {
            // Minimum and Second Minimum Column Index of the current row
            int min1C = -1;
            int min2C = -1;

            // Minimum and Second Minimum Value of current row
            int min1 = -1;
            int min2 = -1;

            for (int col = 0; col < grid.size(); col++) {
                // Select minimum from valid cells of the next row
                int value;
                if (col != nextMin1C) {
                    value = grid[row][col] + nextMin1;
                } else {
                    value = grid[row][col] + nextMin2;
                }

                // Save minimum and second minimum
                if (min1 == -1 || value <= min1) {
                    min2 = min1;
                    min2C = min1C;
                    min1 = value;
                    min1C = col;
                } else if (min2 == -1 || value <= min2) {
                    min2 = value;
                    min2C = col;
                }
            }

            // Change of row. Update nextMin1C, nextMin2C, nextMin1, nextMin2
            nextMin1C = min1C;
            nextMin2C = min2C;
            nextMin1 = min1;
            nextMin2 = min2;
        }

        // Return the minimum from the first row
        return nextMin1;
    }
};