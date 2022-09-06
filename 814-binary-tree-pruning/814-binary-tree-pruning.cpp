class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root!=NULL){
            root->left = pruneTree(root->left);
            root->right = pruneTree(root->right);
            if(!root->left && !root->right && root->val==0)
                return NULL;
        }
        return root;
    }
};