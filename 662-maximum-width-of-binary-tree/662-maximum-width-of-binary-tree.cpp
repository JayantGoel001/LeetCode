class Solution {
public:
    void dfs(TreeNode *root, map<int, int> &left_m, int &ans,int level, int val)
    {
        if (root == NULL) return;
        if(left_m.find(level)==left_m.end())
        {
            left_m[level] = 2*level+1;
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<unsigned int, TreeNode*>> q;
        q.push({0, root});
        unsigned int maxWidth=1;
        //dfs(root, m, ans,0,0);
        while(q.empty()!=true)
        {
            int size = q.size();
            for(int i = 0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                if(curr.second->left){
                    q.push({curr.first*2, curr.second->left});
                }
                if(curr.second->right){
                    q.push({curr.first*2+1, curr.second->right});
                }
            }
            if(q.size()>0)
                maxWidth = max(maxWidth, q.back().first - q.front().first + 1);
        }
        
        return maxWidth;
    }
};