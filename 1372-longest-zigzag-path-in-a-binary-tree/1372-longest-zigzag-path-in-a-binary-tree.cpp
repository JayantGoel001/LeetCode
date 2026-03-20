class Solution {
public:
    int ans = 0;
    int longestZigZag(TreeNode* root, int prev) {
        if (!root) return 0;
        
        int left = longestZigZag(root->left, -1);
        int right = longestZigZag(root->right, 1);

        ans = max(ans, 1 + max(left, right));

        if (prev == 1) return 1 + left;
        else if (prev == -1) return 1 + right;

        return 0;
    }
    int longestZigZag(TreeNode* root) { 
        longestZigZag(root, 0);
        return ans - 1;
    }
};