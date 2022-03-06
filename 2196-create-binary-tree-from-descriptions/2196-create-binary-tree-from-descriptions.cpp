class Solution {
public:
    unordered_map<int,TreeNode*> mp;
    unordered_map<TreeNode*,bool> parent;
    
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        TreeNode *temp;
        for(auto it : des){
            TreeNode *root = nullptr;
            if(mp[it[0]]){
                root = mp[it[0]];
            }else{
                root = new TreeNode(it[0]);
                mp[it[0]] = root;
            }
            TreeNode *child = nullptr;
            if(mp[it[1]]){
                child = mp[it[1]];
            }else{
                child = new TreeNode(it[1]);
                mp[it[1]] = child;
            }
            if(it[2] == 1){
                root->left = child;
            }else{
                root->right = child;
            }
            parent[child] = true;
        }
        for(auto it : mp){
            if(!parent[it.second]){
                return it.second;
            }
        }
        return nullptr;
    }
};