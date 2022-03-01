class Solution {
public:
    stack<TreeNode *> st;
    int kthSmallest(TreeNode* root, int k) {
        while(true){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            
            if(--k == 0){
                return root->val;
            }
            root = root->right;
        }
        return -1;
    }
};