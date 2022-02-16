class Solution {
public:
    bool isValidBST(TreeNode* root,double mini=INT_MIN,double maxi = INT_MAX) {
        if(root){
            if(!(mini <= root->val && root->val <= maxi)){
                return false;
            }
            return isValidBST(root->left,mini,root->val-1.0) && isValidBST(root->right,root->val+1.0,maxi);
        }
        return true;
    }
};