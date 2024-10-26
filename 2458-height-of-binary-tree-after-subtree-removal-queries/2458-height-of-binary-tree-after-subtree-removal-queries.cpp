class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n = 100000;
        // Vectors to store node depths and heights
        vector<int> nodeDepths(n + 1, 0);
        vector<int> subtreeHeights(n + 1, 0);

        // Vectors to store the first and second largest heights at each level
        vector<int> firstLargestHeight(n + 1, 0);
        vector<int> secondLargestHeight(n + 1, 0);

        // Perform DFS to calculate depths and heights
        dfs(root, 0, nodeDepths, subtreeHeights, firstLargestHeight,
            secondLargestHeight);

        vector<int> results;
        results.reserve(queries.size());

        // Process each query
        for (int queryNode : queries) {
            int nodeLevel = nodeDepths[queryNode];

            // Calculate the height of the tree after removing the query node
            if (subtreeHeights[queryNode] == firstLargestHeight[nodeLevel]) {
                results.push_back(nodeLevel + secondLargestHeight[nodeLevel] -
                                  1);
            } else {
                results.push_back(nodeLevel + firstLargestHeight[nodeLevel] -
                                  1);
            }
        }

        return results;
    }

private:
    // Depth-first search to calculate node depths and subtree heights
    int dfs(TreeNode* node, int level, vector<int>& nodeDepths,
            vector<int>& subtreeHeights, vector<int>& firstLargestHeight,
            vector<int>& secondLargestHeight) {
        if (node == nullptr) return 0;

        nodeDepths[node->val] = level;

        // Calculate the height of the current subtree
        int leftHeight = dfs(node->left, level + 1, nodeDepths, subtreeHeights,
                             firstLargestHeight, secondLargestHeight);
        int rightHeight =
            dfs(node->right, level + 1, nodeDepths, subtreeHeights,
                firstLargestHeight, secondLargestHeight);
        int currentHeight = 1 + max(leftHeight, rightHeight);

        subtreeHeights[node->val] = currentHeight;

        // Update the largest and second largest heights at the current level
        if (currentHeight > firstLargestHeight[level]) {
            secondLargestHeight[level] = firstLargestHeight[level];
            firstLargestHeight[level] = currentHeight;
        } else if (currentHeight > secondLargestHeight[level]) {
            secondLargestHeight[level] = currentHeight;
        }

        return currentHeight;
    }
};