class Solution {
    public:
    vector<int> v;
    void inordr(TreeNode *root){
        if(!root){
            return ;
        }
        inordr(root->left);
        v.push_back(root->val);
        inordr(root->right);

    }
    void help(TreeNode *root){
        if(!root){
            return;
        }
        help(root->right);
        root->val=v[v.size()-1];
        v.pop_back();
        help(root->left);

    }
    void recoverTree(TreeNode* root) {
        inordr(root);
        
        sort(v.begin(),v.end());
        help(root);
        return;
    }
};