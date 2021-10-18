#define ptt pair<TreeNode*,TreeNode*>
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<ptt> q;
        
        q.push({root,nullptr});
        
        TreeNode* flagX = nullptr;
        TreeNode* flagY = nullptr;
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                ptt temp = q.front();
                q.pop();
                
                if(temp.first->val == x){
                    flagX = temp.second;
                }
                if(temp.first->val == y){
                    flagY = temp.second;    
                }
                
                if(temp.first->left){
                    q.push({temp.first->left,temp.first});
                }
                if(temp.first->right){
                    q.push({temp.first->right,temp.first});
                }
            }
            if(flagX && flagY && flagX!=flagY){
                return true;
            }
            flagX = nullptr;
            flagY = nullptr;
        }
        return false;
    }
};