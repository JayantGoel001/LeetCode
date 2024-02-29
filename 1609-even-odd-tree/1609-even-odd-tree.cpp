class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        // Create a queue for nodes that need to be visted and add the root
        queue<TreeNode*> queue;
        TreeNode* current = root;
        queue.push(current);

        // Keeps track of whether we are on an even level
        bool even = true;

        // While there are more nodes in the queue
        // Determine the size of the level and handle the nodes
        while (!queue.empty()) {
            int size = queue.size();

            // Prev holds the value of the previous node in this level
            int prev = INT_MAX;
            if (even) {
                prev = INT_MIN;
            }

            // While there are more nodes in this level
            // Remove a node, check whether it satisfies the conditons
            // Add its children to the queue
            while (size > 0) {
                current = queue.front();
                queue.pop();

                // If on an even level, check that the node's value is odd and greater than prev
                // If on an odd level, check that the node's value is even and less than prev
                if ((even && (current->val % 2 == 0 || current->val <= prev)) || 
                        (!even && (current->val % 2 == 1 || current->val >= prev))) {
                    return false;
                }
                prev = current->val;
                if (current->left) {
                    queue.push(current->left);
                }
                if (current->right) {
                    queue.push(current->right);
                }
                // Decrement size, we have handled a node on this level
                size--;
            }
            // Flip the value of even, the next level will be opposite
            even = !even;
        }
        // If every node meets the condtions, the tree is Even-Odd
        return true;
    }
};