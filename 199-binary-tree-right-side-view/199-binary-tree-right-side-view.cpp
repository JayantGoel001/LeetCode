class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v(100,-101);
        if(root){
            queue<TreeNode *> q;
            q.push(root);
            int i = 0;
            while(!q.empty()){
                int size = q.size();
                while(size--){
                    TreeNode *root = q.front();
                    q.pop();
                    v[i] = root->val;
                    
                    if(root->left){
                        q.push(root->left);
                    }
                    if(root->right){
                        q.push(root->right);
                    }
                }
                i++;
            }
        }
        vector<int> output;
        for(auto it : v){
            if(it==-101){
                break;
            }
            output.push_back(it);
        }
        return output;
    }
};