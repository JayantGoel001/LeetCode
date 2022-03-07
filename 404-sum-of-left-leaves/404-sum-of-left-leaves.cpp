class Solution {
public:
    int sum = 0;
    void getLeftSum(TreeNode *root,int d){
        if(root){
            if(d == 0 && !root->left && !root->right){
                sum += root->val;
            }
            getLeftSum(root->left,0);
            getLeftSum(root->right,1);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        getLeftSum(root,-1);
        return sum;
    }
};