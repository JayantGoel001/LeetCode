class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        vector<int> v;
        
        while(!st.empty() || root){
            if(root){
                v.push_back(root->val);
                if(root->right){
                    st.push(root->right);
                }
                root = root->left;
            }else{
                root = st.top();
                st.pop();
            }
        }
        return v;
    }
};