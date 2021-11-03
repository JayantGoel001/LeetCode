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
    void getSum(TreeNode *root,int x){
        if(root){
            int w = 10 * x + root->val;
            
            if(root->left == nullptr && root->right == nullptr){
                sum += w;
            }
            getSum(root->left,w);
            getSum(root->right,w);
        }
    }
    int sumNumbers(TreeNode* root) {
        getSum(root,0);
        return sum;
    }
};