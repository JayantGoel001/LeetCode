class Solution {
public:
    TreeNode *prev = nullptr;
    void flatten(TreeNode* root) {
        if(root){
            TreeNode *left = root->left;
            TreeNode *right = root->right;
            
            if(prev){
                prev->right = root;
                prev->left = nullptr;
            }
            prev = root;
            flatten(left);
            flatten(right);
        }
    }
};