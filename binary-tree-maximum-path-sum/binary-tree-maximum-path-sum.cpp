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
    int ans = INT_MIN;
    
    int inorder(TreeNode *root){
        if(root){
            int left = inorder(root->left);
            int right = inorder(root->right);
            
            ans = max(ans,max(left + right,max(max(left,right),0)) + root->val);
            
            
            return max(max(left,right),0) + root->val;
        }else{
            return 0;
        }
    }
    
    int maxPathSum(TreeNode* root) {
        inorder(root);
        return ans;
    }
};