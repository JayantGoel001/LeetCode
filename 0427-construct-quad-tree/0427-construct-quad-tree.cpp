class Solution {
public:
    int allSame(vector<vector<int>> &grid, int x, int y, int size) {
        int allOnes = true;
        int allZeros = true;

        for(int i = x;i < x + size;i++){
            for(int j = y;j < y + size;j++) {
                allOnes &= (grid[i][j] == 1);
                allZeros &= (grid[i][j] == 0);
            }
        }

        return allOnes ? 1 : (allZeros ? 0 : -1);
    }
    Node *construct(vector<vector<int>> &grid, int x, int y, int size) {
        int isLeaf = allSame(grid,x,y,size);
        if (isLeaf != -1) return new Node(isLeaf, true);

        Node *node = new Node(true, false);
        int midX = x + size / 2;
        int midY = y + size / 2;

        node->topLeft = construct(grid, x, y, size/2);
        node->topRight = construct(grid, x, midY, size/2);
        node->bottomLeft = construct(grid, midX, y, size/2);
        node->bottomRight = construct(grid, midX, midY, size/2);

        return node;
    }
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size());
    }
};