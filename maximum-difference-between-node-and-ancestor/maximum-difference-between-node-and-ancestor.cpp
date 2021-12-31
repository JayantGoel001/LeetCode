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
    int ans = INT_MIN;
    
    pair<int, int> helper(TreeNode *root) {
        if(!root) {
            pair<int, int> p;
            p.first = -1;
            p.second = 100001;
            return p;
        }
        pair<int, int> l = helper(root->left);
        pair<int, int> r = helper(root->right);
        pair<int, int> p;
        
        p.first = max({r.first, l.first, root->val});
        p.second = min({r.second, l.second, root->val});
        ans = max({ans, abs(root->val - p.first), abs(root->val - p.second)});
        return p;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        helper(root);
        return ans;
    }
};