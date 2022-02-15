class Solution {
public:
    bool ans = true;
    int height(TreeNode *root){
        if(root){
            int left = height(root->left);
            int right = height(root->right);
            
            ans &= (abs(left - right)<=1);
            
            return max(left,right) + 1;
        }
        return 0;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        
        return ans;
    }
};