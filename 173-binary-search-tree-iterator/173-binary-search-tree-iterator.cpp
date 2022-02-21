class BSTIterator {
public:
    stack<TreeNode*> st;
    void Inorder(TreeNode *root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        Inorder(root);
    }
    
    int next() {
        TreeNode *top = st.top();
        st.pop();
        Inorder(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};