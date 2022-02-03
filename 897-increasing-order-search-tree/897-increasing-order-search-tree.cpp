class Solution {
public:
    TreeNode *ibst;
    void convert(TreeNode *root){
        if(root){
            convert(root->left);
            ibst->right = new TreeNode(root->val);
            ibst = ibst->right;
            convert(root->right);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *head = new TreeNode(0);
        ibst = head;
        
        convert(root);
        return head->right;
    }
};