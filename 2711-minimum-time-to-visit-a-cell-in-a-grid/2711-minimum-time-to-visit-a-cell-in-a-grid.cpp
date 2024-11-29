class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        // If both initial moves require more than 1 second, impossible to
        // proceed
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        int rows = grid.size(), cols = grid[0].size();
        // Possible movements: down, up, right, left
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Priority queue stores {time, row, col}
        // Ordered by minimum time to reach each cell
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int time = curr[0], row = curr[1], col = curr[2];

            // Check if reached target
            if (row == rows - 1 && col == cols - 1) {
                return time;
            }

            // Skip if cell already visited
            if (visited[row][col]) {
                continue;
            }
            visited[row][col] = true;

            // Try all four directions
            for (auto& d : directions) {
                int nextRow = row + d[0], nextCol = col + d[1];
                if (!isValid(visited, nextRow, nextCol)) {
                    continue;
                }

                // Calculate the wait time needed to move to next cell
                int waitTime =
                    ((grid[nextRow][nextCol] - time) % 2 == 0) ? 1 : 0;
                int nextTime = max(grid[nextRow][nextCol] + waitTime, time + 1);
                pq.push({nextTime, nextRow, nextCol});
            }
        }
        return -1;
    }

private:
    // Checks if given cell coordinates are valid and unvisited
    bool isValid(vector<vector<bool>>& visited, int row, int col) {
        return row >= 0 && col >= 0 && row < visited.size() &&
               col < visited[0].size() && !visited[row][col];
    }
};