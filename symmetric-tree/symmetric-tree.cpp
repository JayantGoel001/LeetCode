class Solution {
public:
    bool util(TreeNode *left,TreeNode *right){
        if(left && right){
            if(left->val != right->val){
                return false;
            }
            
            return util(left->left,right->right) && util(left->right,right->left);
        }else if(left == nullptr && right == nullptr){
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return util(root,root);
    }
};