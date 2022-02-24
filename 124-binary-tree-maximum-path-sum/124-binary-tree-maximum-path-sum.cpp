class Solution {
public:
    int ans = INT_MIN;
    int getSum(TreeNode *root){
        if(root){
            int left = getSum(root->left);
            int right = getSum(root->right);
            
            ans =  max(ans,max({left, right, left + right, 0}) + root->val);
                
            return max({left, right, 0}) + root->val;
        }
        return 0;
    }
    int maxPathSum(TreeNode* root) {
        getSum(root);
        return ans;
    }
};