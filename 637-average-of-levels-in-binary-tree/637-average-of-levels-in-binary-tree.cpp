class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        // while there are nodes remaining to be visited
        while(!q.empty()){
            double temp = q.size();
            double sum = 0;
            // iterating each level of binary tree
            for(int i = 0; i < temp; i++){
                auto tt = q.front();
                q.pop();
                sum += (tt->val);
				// check for not NULL and pushing into queue.
                if(tt->left){
                    q.push(tt->left);
                }
                if(tt->right){
                    q.push(tt->right);
                }
            }
            ans.push_back(sum/ temp);
        }
        return ans;
    }
};