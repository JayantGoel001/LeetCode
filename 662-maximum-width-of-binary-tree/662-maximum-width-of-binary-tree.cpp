#define pti pair<TreeNode *,unsigned int>
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pti> q;
        q.push({root,0});
        unsigned int maxi = 0;
        while(!q.empty()){
            int size = q.size();
            unsigned int diffY = 0;
            unsigned int diffX = 0;
            for(int i=0;i<size;i++){
                pti top = q.front();
                q.pop();
                
                if(i == 0){
                    diffX = top.second;
                }
                if(i == size-1){
                    diffY = top.second;
                }
                
                if(top.first->left){
                    q.push({top.first->left,2 * top.second});
                }
                if(top.first->right){
                    q.push({top.first->right,2 * top.second + 1});
                }
            }
            maxi = max(maxi,diffY - diffX + 1);
        }
        return maxi;
    }
};