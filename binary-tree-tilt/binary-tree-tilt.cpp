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
    int findTiltUtil(TreeNode *root){
        if(root){
            int leftSum = findTiltUtil(root->left);
            int rightSum = findTiltUtil(root->right);
            
            sum += abs(leftSum - rightSum);
            return root->val + leftSum + rightSum;
        }else{
            return 0;
        }
    }
    int findTilt(TreeNode* root) {
        findTiltUtil(root);
        return sum;
    }
};