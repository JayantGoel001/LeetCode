/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root){
            if((root->val >= p->val && root->val <= q->val) || (root->val <= p->val && root->val >= q->val)){
                return root;
            }
            TreeNode *left = lowestCommonAncestor(root->left, p, q);
            TreeNode *right = lowestCommonAncestor(root->right, p, q);
            if(left || right){
                if(left){
                    return left;
                }
                if(right){
                    return right;
                }
            }
        }
        return nullptr;
    }
};