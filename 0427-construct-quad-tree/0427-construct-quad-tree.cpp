/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool checkAllSame(vector<vector<int>>& grid,int i,int j,int n){
        int initial = grid[i][j];
        for(int x = i;x < i + n;x++){
            for(int y = j;y < j + n;y++){
                if(grid[x][y] != initial){
                    return false;
                }
            }
        }
        return true;
    }
    Node *createQuadTree(vector<vector<int>>& grid,int i,int j,int n){
        Node *root = nullptr;
        
        if(checkAllSame(grid, i, j, n)){
            root = new Node(grid[i][j], true);
        }else{
            root = new Node(grid[i][j], false);

            root->topLeft = createQuadTree(grid, i, j, n/2);
            root->topRight = createQuadTree(grid, i, j + n/2, n/2);
            root->bottomLeft = createQuadTree(grid, i + n/2, j, n/2);
            root->bottomRight = createQuadTree(grid, i + n/2, j + n/2, n/2);
        }
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        return createQuadTree(grid, 0, 0, grid.size());
    }
};