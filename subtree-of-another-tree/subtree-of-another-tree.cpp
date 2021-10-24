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
    bool checkSubTree(TreeNode *root,TreeNode *sub){
        if(root && sub){
            if(root->val != sub->val){
                return false;
            }
            return checkSubTree(root->left,sub->left) && checkSubTree(root->right,sub->right);
        }else if(root == nullptr && sub == nullptr){
            return true;
        }else{
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root && subRoot){
            if(root->val == subRoot->val && checkSubTree(root,subRoot)){
                return root;
            }
            return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        }
        return false;
    }
};