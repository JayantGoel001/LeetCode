class Solution {
public:
    int sum = 0;
    
    void findSum(TreeNode *root, int x){
        if(root){
            x = x * 10 + root->val;
            if(!root->left && !root->right){
                sum += x;
            }
            
            findSum(root->left, x);
            findSum(root->right, x);
        }
        
    }
    int sumNumbers(TreeNode* root) {
        findSum(root, 0);
        return sum;
    }
};