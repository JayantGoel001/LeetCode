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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(cloned){
            if(cloned->val == target->val && original == target){
                return cloned;
            }
            TreeNode *left = getTargetCopy(original->left,cloned->left,target);
            TreeNode *right = getTargetCopy(original->right,cloned->right,target);
            if(left){
                return left;
            }
            if(right){
                return right;
            }
        }
        return nullptr;
    }
};