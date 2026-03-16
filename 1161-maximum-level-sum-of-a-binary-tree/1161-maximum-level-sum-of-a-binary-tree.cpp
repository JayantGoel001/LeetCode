/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxi = INT_MIN, x = 0;
        if (!root) return x;

        queue<TreeNode*> q;
        q.push(root);
        int currLevel = 0;
        while(!q.empty()) {
            int size = q.size();
            int sum = 0;
            currLevel++;
            while(size--) {
                TreeNode *top = q.front();
                q.pop();

                sum += top->val;

                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }

            if (sum > maxi) {
                maxi = sum;
                x = currLevel;
            }
        }
        return x;
    }
};