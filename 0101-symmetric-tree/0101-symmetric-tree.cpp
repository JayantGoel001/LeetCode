class Solution {
public:
    bool isSym(TreeNode *left, TreeNode *right){
        if(left && right){
            if(left->val != right->val){
                return false;
            }
            return isSym(left->left, right->right) && isSym(left->right, right->left);
        }else{
            return !left && !right;
        }
    }
    bool isSymmetric(TreeNode* root) {
        return isSym(root->left, root->right);
    }
};