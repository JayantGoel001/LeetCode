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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if (!root) return v;

        queue<TreeNode*> q;
        q.push(root);
        int index = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                TreeNode *top = q.front();
                q.pop();

                if (size == 0) v.push_back(top->val);

                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }
        }
        return v;
    }
};