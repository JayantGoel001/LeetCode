class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned int>> q;
        q.push({root,0});
        
        unsigned int maxi = 0;
        
        while(!q.empty()){
            int size = q.size();
            unsigned int diffX,diffY;
            
            for(int i=0;i<size;i++){
                pair<TreeNode*,unsigned int> p = q.front();
                q.pop();
                
                if(i == 0){
                    diffX = p.second;
                }
                if(i == size-1){
                    diffY = p.second;
                }
                
                if(p.first->left){
                    q.push({p.first->left,2 * p.second});
                }
                
                if(p.first->right){
                    q.push({p.first->right,2 * p.second + 1});
                }
            }
            maxi = max(maxi,diffY - diffX + 1);
        }
        return maxi;
    }
};