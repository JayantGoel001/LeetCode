#define pii pair<TreeNode*,unsigned>
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pii> q;
        q.push({root, 0});
        unsigned maxi = 0;
        while(!q.empty()){
            int size = q.size();
            unsigned first = INT_MAX;
            unsigned second = INT_MAX;
            for(int i=0;i<size;i++){
                pii top = q.front();
                q.pop();
                if(i == 0){
                    first = top.second;
                }
                if(i == size - 1){
                    second = top.second;
                }
                
                if(top.first->left){
                    q.push({top.first->left, 2 * top.second});
                }
                if(top.first->right){
                    q.push({top.first->right, 2 * top.second + 1});
                }
            }
            maxi = max(maxi, second - first + 1);
        }
        return maxi;
    }
};