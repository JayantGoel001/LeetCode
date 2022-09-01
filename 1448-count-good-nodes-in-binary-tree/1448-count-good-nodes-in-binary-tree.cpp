class Solution {
public:
    int count = 0;
    void dfs(TreeNode* node,int curMax){
        if (!node) return;
        
        if (node->val >= curMax){
            count++;
            curMax = node->val;
        }
        dfs(node->left, curMax);
        dfs(node->right, curMax);
    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return count;
    }
};