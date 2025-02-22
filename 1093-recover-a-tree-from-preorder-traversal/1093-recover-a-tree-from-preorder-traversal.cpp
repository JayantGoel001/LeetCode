class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        // Stores the last node at each depth level
        vector<TreeNode*> levels;
        int index = 0, n = traversal.size();

        while (index < n) {
            // Count depth (number of dashes)
            int depth = 0;
            while (index < n && traversal[index] == '-') {
                depth++;
                index++;
            }

            // Extract node value
            int value = 0;
            while (index < n && isdigit(traversal[index])) {
                value = value * 10 + (traversal[index] - '0');
                index++;
            }

            // Create the new node
            TreeNode* node = new TreeNode(value);

            // Adjust levels list to match the current depth
            if (depth < levels.size()) {
                levels[depth] = node;
            } else {
                levels.push_back(node);
            }

            // Attach the node to its parent
            if (depth > 0) {
                TreeNode* parent = levels[depth - 1];
                if (parent->left == nullptr) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            }
        }

        // The root node is always at index 0
        return levels[0];
    }
};