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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;

        if (root->val == key) {
            if (root->right) {
                TreeNode *temp = root->right;
                while (temp->left) temp = temp->left;
                temp->left = root->left;

                return root->right;
            }
            if (root->left) return root->left;
            return nullptr;
        }

        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);

        return root;
    }
};