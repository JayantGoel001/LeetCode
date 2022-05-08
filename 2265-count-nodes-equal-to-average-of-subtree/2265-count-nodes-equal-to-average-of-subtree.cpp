#define pii pair<int,int>
class Solution {
public:
    int count = 0;
    pii inorder(TreeNode *root){
        if(root){
            pii left = inorder(root->left);
            pii right = inorder(root->right);
            
            int sum = left.first + right.first + root->val;
            int c = left.second + right.second + 1;
            
            count += (sum/c == root->val);
            return {sum, c};
        }
        return {0,0};
    }
    int averageOfSubtree(TreeNode* root) {
        inorder(root);
        return count;
    }
};