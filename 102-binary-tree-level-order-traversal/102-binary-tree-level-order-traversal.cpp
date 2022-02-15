class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root){
            return v;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            v.push_back(vector<int>());
            while(size--){
                root = q.front();
                q.pop();
                
                v.back().push_back(root->val);
                
                if(root->left){
                    q.push(root->left);
                }
                
                if(root->right){
                    q.push(root->right);
                }
            }
        }
        return v;
    }
};