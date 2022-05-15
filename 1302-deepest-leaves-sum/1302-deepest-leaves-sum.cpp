class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int sum;
        while(!q.empty()){
            int size = q.size();
            
            if(size != 0){
                sum = 0;
            }
            for(int i = 0;i<size;i++){
                TreeNode *top = q.front();
                q.pop();
                
                sum += top->val;
                
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
        }
        return sum;
    }
};