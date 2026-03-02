class Solution {
public:
    int allSame(vector<vector<int>> &grid, int x, int y, int z, int w) {
        int allOnes = true;
        int allZeros = true;

        for(int i=x;i<=z;i++){
            for(int j=y;j<=w;j++) {
                allOnes &= (grid[i][j] == 1);
                allZeros &= (grid[i][j] == 0);
            }
        }

        return allOnes ? 1 : (allZeros ? 0 : -1);
    }
    Node *construct(vector<vector<int>> &grid, int x, int y, int z, int w) {
        int isLeaf = allSame(grid,x,y,z,w);
        if (isLeaf != -1) return new Node(isLeaf, true);

        Node *node = new Node(true, false);
        int midX = x + (z - x) / 2;
        int midY = y + (w - y) / 2;

        node->topLeft = construct(grid, x, y, midX, midY);
        node->topRight = construct(grid, x, midY + 1, midX, w);
        node->bottomLeft = construct(grid, midX + 1, y, z, midY);
        node->bottomRight = construct(grid, midX + 1, midY + 1, z, w);

        return node;
    }
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size()-1, grid.size()-1);
    }
};