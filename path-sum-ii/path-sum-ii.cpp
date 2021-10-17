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
    vector<vector<int>> v;
    
    void getPath(TreeNode* root, int targetSum,vector<int> &path){
        if(root){
            targetSum -= root->val;
            path.push_back(root->val);
            
            if(targetSum == 0 && root->left == nullptr && root->right == nullptr){
                v.push_back(path);
            }else{
                getPath(root->left,targetSum,path);
                getPath(root->right,targetSum,path);
            }
            
            targetSum += root->val;
            path.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        getPath(root,targetSum,path);
        return v;
    }
};