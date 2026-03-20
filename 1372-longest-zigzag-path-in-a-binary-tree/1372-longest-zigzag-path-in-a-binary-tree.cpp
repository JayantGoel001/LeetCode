class Solution {
public:
    int ans = 0;
    void longestZigZag(TreeNode* root, int left, int right) {
        if (!root) return;

        ans = max(ans, max(left, right));

        longestZigZag(root->left, 0, left + 1);
        longestZigZag(root->right, right + 1, 0);

    }
    int longestZigZag(TreeNode* root) { 
        longestZigZag(root, 0, 0);
        return ans;
    }
};