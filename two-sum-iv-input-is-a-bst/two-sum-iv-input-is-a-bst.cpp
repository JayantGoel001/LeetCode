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
    vector<int> v;
    void inorder(TreeNode *root){
        if(root){
            inorder(root->left);
            v.push_back(root->val);
            inorder(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int i = 0;
        int j = v.size()-1;
        
        while(i<j){
            if(v[i] + v[j] == k){
                return true;
            }else if(v[i] + v[j] > k){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};