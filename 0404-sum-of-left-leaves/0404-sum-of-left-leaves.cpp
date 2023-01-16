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
    int sumOfLeftLeaves(TreeNode* root, bool l = 0) {
        if(root){
            if(l && root->left == nullptr && root->right == nullptr){
                return root->val;
            }
            int lsum = sumOfLeftLeaves(root->left, 1);
            int rsum = sumOfLeftLeaves(root->right, 0);
            return lsum + rsum;
        }
        return 0;
    }
};