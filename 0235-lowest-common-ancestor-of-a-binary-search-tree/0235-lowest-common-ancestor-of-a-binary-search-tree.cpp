class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root){
            if((p->val <= root->val && root->val <= q->val) || (q->val <= root->val && root->val <= p->val)){
                return root;
            }
            TreeNode *left = lowestCommonAncestor(root->left, p,q);
            TreeNode *right = lowestCommonAncestor(root->right, p , q);
            if(left){
                return left;
            }
            if(right){
                return right;
            }
            return nullptr;
        }
        return root;
    }
};