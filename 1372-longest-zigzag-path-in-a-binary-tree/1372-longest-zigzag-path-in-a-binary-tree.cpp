/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxi = 0;
    void dfs(TreeNode *root, bool goLeft, int steps){
        if(root){
            maxi = max(maxi, steps);
            dfs(root->left, false, goLeft? steps + 1 : 1);
            dfs(root->right, true, goLeft? 1 : steps + 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root, false, 0);
        dfs(root, true, 0);
        
        return maxi;
    }
};