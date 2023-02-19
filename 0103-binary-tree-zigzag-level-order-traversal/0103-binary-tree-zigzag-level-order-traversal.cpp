class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root){
            return v;
        }
        queue<TreeNode *> q;
        q.push(root);
        bool h = true;
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
            if(!h){
                reverse(v.back().begin(),v.back().end());
            }
            h = !h;
        }
        return v;
    }
};