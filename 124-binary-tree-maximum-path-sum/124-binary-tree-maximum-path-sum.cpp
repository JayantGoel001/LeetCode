class Solution {
public:
    int ans = INT_MIN;
    
    int getMaxSum(TreeNode *root){
        if(root){
            int left = getMaxSum(root->left);
            int right = getMaxSum(root->right);
            
            ans = max(ans, max({left, right, left + right, 0}) + root->val);
            
            return max({left, right, 0}) + root->val;
        }
        return 0;
    }
    
    int maxPathSum(TreeNode* root) {
        getMaxSum(root);
        return ans;
    }
};