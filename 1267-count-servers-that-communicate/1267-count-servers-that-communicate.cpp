class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int communicableServersCount = 0;

        for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
            int rowCounts = 0;
            int serverColumnIndex = -1;

            // Count the number of servers in the current row and record the
            // first server's column index.
            for (int colIndex = 0; colIndex < cols; ++colIndex) {
                if (grid[rowIndex][colIndex]) {
                    if (rowCounts == 0) {
                        serverColumnIndex = colIndex;
                    }
                    rowCounts += 1;
                }
            }

            // If more than one server in the row, it can communicate
            bool canCommunicate = (rowCounts != 1);

            // If there's only one server in the row, check if there's a server
            // in the same column in another row.
            if (!canCommunicate) {
                for (int i = 0; i < rows; ++i) {
                    if (i != rowIndex && grid[i][serverColumnIndex]) {
                        canCommunicate = true;
                        break;
                    }
                }
            }

            // If the server can communicate, add rowCounts to the result.
            if (canCommunicate) {
                communicableServersCount += rowCounts;
            }
        }

        return communicableServersCount;
    }
};