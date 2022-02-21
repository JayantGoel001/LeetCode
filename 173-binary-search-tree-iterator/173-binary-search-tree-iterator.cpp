class BSTIterator {
public:
    vector<int> v;
    int i = 0;
    void Inorder(TreeNode *root){
        if(root){
            Inorder(root->left);
            v.push_back(root->val);
            Inorder(root->right);
        }
    }
    BSTIterator(TreeNode* root) {
        Inorder(root);
    }
    
    int next() {
        return v[i++];
    }
    
    bool hasNext() {
        return i < v.size();
    }
};