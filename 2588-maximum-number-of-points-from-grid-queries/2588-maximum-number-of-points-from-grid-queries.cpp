// Represents a cell in the grid with row index, column index, and value
class Cell {
public:
    int row;
    int col;
    int value;
    Cell(int r, int c, int v) : row(r), col(c), value(v) {}
};

// Represents a query with its original index and value
class Query {
public:
    int index;
    int value;
    Query(int i, int v) : index(i), value(v) {}
};

bool operator<(const Query& a, const Query& b) { return a.value < b.value; }

bool operator<(const Cell& a, const Cell& b) { return a.value < b.value; }

class UnionFind {
private:
    vector<int> parent;
    vector<int> size;

public:
    // Initialize all parents to -1 (disjoint sets) and each component starts
    // with size 1
    UnionFind(int n) : parent(vector<int>(n, -1)), size(vector<int>(n, 1)) {}

    // Find with path compression
    int find(int node) {
        // If negative, it's the root
        if (parent[node] < 0) {
            return node;
        }
        // Path compression
        return parent[node] = find(parent[node]);
    }

    // Union by size (merge smaller tree into larger tree)
    bool union_nodes(int nodeA, int nodeB) {
        int rootA = find(nodeA);
        int rootB = find(nodeB);
        // Already connected
        if (rootA == rootB) {
            return false;
        }
        if (size[rootA] > size[rootB]) {
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        } else {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
        return true;
    }

    // Get the size of the component containing a given node
    int getSize(int node) { return size[find(node)]; }
};

// Right, Left, Down, Up
const vector<int> ROW_DIRECTIONS = {0, 0, 1, -1};
// Corresponding column moves
const vector<int> COL_DIRECTIONS = {1, -1, 0, 0};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rowCount = grid.size(), colCount = grid[0].size();
        int totalCells = rowCount * colCount;

        // Store queries with their original indices to maintain result order
        vector<Query> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back(Query(i, queries[i]));
        }
        // Sort queries in ascending order
        sort(sortedQueries.begin(), sortedQueries.end());

        // Store all grid cells and sort them by value
        vector<Cell> sortedCells;
        for (int row = 0; row < rowCount; row++) {
            for (int col = 0; col < colCount; col++) {
                sortedCells.push_back(Cell(row, col, grid[row][col]));
            }
        }
        // Sort cells by value
        sort(sortedCells.begin(), sortedCells.end());

        // Union-Find to track connected components
        UnionFind uf = UnionFind(totalCells);
        vector<int> result(queries.size());
        int cellIndex = 0;

        // Process queries in sorted order
        for (Query query : sortedQueries) {
            // Process cells whose values are smaller than the current query
            // value
            while (cellIndex < totalCells &&
                   sortedCells[cellIndex].value < query.value) {
                int row = sortedCells[cellIndex].row;
                int col = sortedCells[cellIndex].col;
                // Convert 2D position to 1D index
                int cellId = row * colCount + col;

                // Merge the current cell with its adjacent cells that have
                // already been processed
                for (int direction = 0; direction < 4; direction++) {
                    int newRow = row + ROW_DIRECTIONS[direction];
                    int newCol = col + COL_DIRECTIONS[direction];

                    // Check if the new cell is within bounds and its value is
                    // smaller than the query value
                    if (newRow >= 0 && newRow < rowCount && newCol >= 0 &&
                        newCol < colCount &&
                        grid[newRow][newCol] < query.value) {
                        uf.union_nodes(cellId, newRow * colCount + newCol);
                    }
                }
                cellIndex++;
            }
            // Get the size of the connected component containing the top-left
            // cell (0,0)
            result[query.index] = query.value > grid[0][0] ? uf.getSize(0) : 0;
        }
        return result;
    }
};