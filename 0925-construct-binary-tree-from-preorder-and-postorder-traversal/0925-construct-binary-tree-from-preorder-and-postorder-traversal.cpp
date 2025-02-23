class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int preIndex = 0;
        int postIndex = 0;
        return constructTree(preIndex, postIndex, preorder, postorder);
    }

private:
    // Helper function to recursively build the tree
    TreeNode* constructTree(int& preIndex, int& postIndex,
                            vector<int>& preorder, vector<int>& postorder) {
        // Create a new node with the value at the current preorder index
        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++;  // Mark this node as created

        // Recursively construct the left subtree if the root is not the last of
        // its subtree
        if (root->val != postorder[postIndex]) {
            root->left =
                constructTree(preIndex, postIndex, preorder, postorder);
        }

        // Recursively construct the right subtree if the root is still not the
        // last of its subtree
        if (root->val != postorder[postIndex]) {
            root->right =
                constructTree(preIndex, postIndex, preorder, postorder);
        }

        // Mark this node and its subtree as fully processed
        postIndex++;

        return root;
    }
};