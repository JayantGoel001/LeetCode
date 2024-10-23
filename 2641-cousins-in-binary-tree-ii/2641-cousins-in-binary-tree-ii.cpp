class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int previousLevelSum = root->val;

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            int currentLevelSum = 0;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                // Update node value to cousin sum.
                currentNode->val = previousLevelSum - currentNode->val;

                // Calculate sibling sum.
                int siblingSum =
                    (currentNode->left != nullptr ? currentNode->left->val
                                                  : 0) +
                    (currentNode->right != nullptr ? currentNode->right->val
                                                   : 0);

                if (currentNode->left != nullptr) {
                    currentLevelSum +=
                        currentNode->left
                            ->val;  // Accumulate current level sum.
                    currentNode->left->val =
                        siblingSum;  // Update left child's value.
                    nodeQueue.push(
                        currentNode->left);  // Add to queue for next level.
                }
                if (currentNode->right != nullptr) {
                    currentLevelSum +=
                        currentNode->right
                            ->val;  // Accumulate current level sum.
                    currentNode->right->val =
                        siblingSum;  // Update right child's value.
                    nodeQueue.push(
                        currentNode->right);  // Add to queue for next level.
                }
            }

            previousLevelSum = currentLevelSum;  // Update previous level sum
                                                 // for next iteration.
        }
        return root;
    }
};