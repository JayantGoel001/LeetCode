class Solution {
public:
    long kthLargestLevelSum(TreeNode* root, int k) {
        // min heap of size k
        // at the end, top element is kth largest
        priority_queue<long, vector<long>, greater<long> > pq;

        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        while (!bfsQueue.empty()) {
            // level order traversal
            int size = bfsQueue.size();
            long sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* poppedNode = bfsQueue.front();
                bfsQueue.pop();
                sum += poppedNode->val;
                if (poppedNode->left != NULL) {
                    // add left child
                    bfsQueue.push(poppedNode->left);
                }
                if (poppedNode->right != NULL) {
                    // add right child
                    bfsQueue.push(poppedNode->right);
                }
            }
            pq.push(sum);
            if (pq.size() > k) {
                // evict top element
                pq.pop();
            }
        }
        if (pq.size() < k) return -1;
        return pq.top();
    }
};