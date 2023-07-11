#define pti pair<TreeNode *,int>
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    
    void DFS(TreeNode *root,TreeNode *prev = nullptr){
        if(root){
            parent[root] = prev;
            DFS(root->left,root);
            DFS(root->right,root);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        DFS(root);
        
        queue<pti> q;
        q.push({target,k});
        unordered_map<TreeNode*,bool> vis;
        
        vector<int> v;
        
        while(!q.empty()){
            pti top = q.front();
            q.pop();
            
            if(!vis[top.first]){
                
                vis[top.first] = true;
                
                if(top.second == 0){
                    v.push_back(top.first->val);
                }else{
                    if(top.first->left && !vis[top.first->left]){
                        q.push({top.first->left,top.second - 1});
                    }
                    
                    if(top.first->right && !vis[top.first->right]){
                        q.push({top.first->right,top.second - 1});
                    }
                    
                    if(parent[top.first] && !vis[parent[top.first]]){
                        q.push({parent[top.first], top.second - 1});
                    }
                }
            }
        }
        return v;
    }
};