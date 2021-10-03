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
    bool isValidBST(TreeNode* root,double mini = INT_MIN,double maxi = INT_MAX) {
        if(root){
            if(!(root->val >= mini && root->val <= maxi)){
                return false;
            }
            return isValidBST(root->left,mini,root->val-1.0) && isValidBST(root->right,root->val+1.0,maxi);
        }else{
            return true;
        }
    }
};