class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        vector<int> v;
       
        while(!st.empty() || root){
            if(root){
                st.push(root);
                root = root->left;
            }else{
                root = st.top();
                st.pop();
                v.push_back(root->val);
                
                root = root->right;
            }
        }
        return v;
    }
};