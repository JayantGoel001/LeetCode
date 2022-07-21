class Solution {
public:
    
    bool isSym(TreeNode *left,TreeNode *right){
        if(left && right){
            if(left->val != right->val){
                return false;
            }
            return isSym(left->left,right->right) && isSym(left->right,right->left); 
        }else if(!left && !right){
            return true;
        }
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        return root ? isSym(root->left,root->right) : true;
    }
};