class Solution {
public:
    int maxi = INT_MIN;
    
    int calculateMPS(TreeNode *root){
        if(root){
            int left = calculateMPS(root->left);
            int right = calculateMPS(root->right);
            
            maxi = max(maxi,max({left,right,left + right,0}) + root->val);
            
            return max({left,right,0}) + root->val;
        }
        return 0;
    }
    
    int maxPathSum(TreeNode* root) {
        calculateMPS(root);
        return maxi;
    }
};