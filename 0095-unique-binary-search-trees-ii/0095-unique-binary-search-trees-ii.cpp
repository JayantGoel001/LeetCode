class Solution {
public:
    vector<TreeNode*> generateTrees(int n,int start = 1) {
        vector<TreeNode*> v;
        
        if(start > n){
            v.push_back(nullptr);
            return v;
        }
        for(int i=start;i<=n;i++){
            vector<TreeNode*> left = generateTrees(i-1,start);
            vector<TreeNode*> right = generateTrees(n,i+1);
            
            for(auto itl : left){
                for(auto itr : right){
                    TreeNode *root = new TreeNode(i);
                    root->left = itl;
                    root->right = itr;
                    v.push_back(root);
                }
            }
        }
        return v;
    }
};