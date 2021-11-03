class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        while(true){
            while(root){
                st.push(root);
                root = root->left;
            }
            
            root = st.top();
            st.pop();
            k--;
            if(k == 0){
                return root->val;
            }
            root = root->right;
        }
    }
};