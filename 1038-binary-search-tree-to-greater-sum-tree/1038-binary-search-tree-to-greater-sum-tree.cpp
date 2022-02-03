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
    int sum = 0;
    void convert(TreeNode *root){
        if(root){
            convert(root->right);
            sum += root->val;
            root->val = sum;
            convert(root->left);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        convert(root);
        return root;
    }
};