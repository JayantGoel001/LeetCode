class Solution {
public:
    TreeNode *insert(TreeNode *root,int val){
        if(root){
            if(root->val > val){
                root->left = insert(root->left,val);
            }else{
                root->right = insert(root->right,val);
            }
            return root;
        }else{
            return new TreeNode(val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        root = insert(root,val);
        return root;
    }
};