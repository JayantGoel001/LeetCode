class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* current = front;
        int prefixSum = 0;
        unordered_map<int, ListNode*> prefixSumToNode;
        while (current != nullptr) {
            // Add current's value to the prefix sum
            prefixSum += current->val;

            // If prefixSum is already in the hashmap, 
            // we have found a zero-sum sequence:
            if (prefixSumToNode.find(prefixSum) != prefixSumToNode.end()) {
                ListNode* prev = prefixSumToNode[prefixSum];
                current = prev->next;

                // Delete zero sum nodes from hashmap
                // to prevent incorrect deletions from linked list
                int p = prefixSum + current->val;
                while (p != prefixSum) {
                    prefixSumToNode.erase(p);
                    current = current->next;
                    p += current->val;
                }

                // Make connection from the node before 
                // the zero sum sequence to the node after
                prev->next = current->next;
            } else {
                // Add new prefixSum to hashmap
                prefixSumToNode[prefixSum] = current;
            }
            // Progress to next element in list
            current = current->next;
        }
        return front->next;
    }
};