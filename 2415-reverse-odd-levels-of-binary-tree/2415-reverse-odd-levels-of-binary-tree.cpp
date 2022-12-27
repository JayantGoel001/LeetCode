class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        
        q.push(root);
        
        bool odd = false;
        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> v;
            for(int i=0;i<size;i++){
                TreeNode *node = q.front();
                q.pop();
                
                if(odd){
                    v.push_back(node);
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                
            }
            for(int i=0;i<v.size()/2;i++){
                int x = v[i]->val;
                v[i]->val = v[v.size() - i - 1]->val;
                v[v.size() - i - 1]->val = x;
            }
            odd = !odd;
        }
        
        return root;
    }
};