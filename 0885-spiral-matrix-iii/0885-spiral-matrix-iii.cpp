class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        // Store all possible directions in an array.
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> traversed;

        // Initial step size is 1, value of d represents the current direction.
        for (int step = 1, direction = 0; traversed.size() < rows * cols;) {
            // direction = 0 -> East, direction = 1 -> South
            // direction = 2 -> West, direction = 3 -> North
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < step; ++j) {
                    // Validate the current position
                    if (rStart >= 0 && rStart < rows && cStart >= 0 &&
                        cStart < cols) {
                        traversed.push_back({rStart, cStart});
                    }
                    // Make changes to the current position.
                    rStart += dir[direction][0];
                    cStart += dir[direction][1];
                }

                direction = (direction + 1) % 4;
            }
            ++step;
        }
        return traversed;
    }
};