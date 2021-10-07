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
    vector<string> v;
    
    void createPath(TreeNode *root,string str = ""){
        if(root){
            string s = to_string(root->val);
            if(root->left == nullptr && root->right == nullptr){
                v.push_back(str+s);
            }else{
                
                s.append("->");
                createPath(root->left,str + s);
                createPath(root->right,str + s);
            }
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        createPath(root);
        
        return v;
    }
};