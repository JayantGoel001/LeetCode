class Solution {
public:
    int ans = 0;
    
    int getDiameter(TreeNode *root){
        if(root){
            int left = getDiameter(root->left);
            int right = getDiameter(root->right);
            
            ans = max({ans,left + right});
            return max(left,right) + 1;
        }
        return 0;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        getDiameter(root);
        return ans;
    }
};