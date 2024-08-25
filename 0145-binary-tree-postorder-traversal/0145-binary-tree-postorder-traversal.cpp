class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        
        vector<int> v;
        while(!st.empty() || root){
            if(root){
                st.push(root);
                v.push_back(root->val);
                root = root->right;
            }else{
                root = st.top()->left;
                st.pop();
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};