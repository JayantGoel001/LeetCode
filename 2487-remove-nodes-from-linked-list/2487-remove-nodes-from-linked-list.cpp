class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nextTemp = nullptr;

        // Set each node's next pointer to the previous node
        while (current != nullptr) {
            nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }
        
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        // Reverse the original linked list
        head = reverseList(head);

        int maximum = 0;
        ListNode* prev = nullptr;
        ListNode* current = head;

        // Traverse the list deleting nodes
        while (current != nullptr) {
            maximum = max(maximum, current->val);

            // Delete nodes that are smaller than maximum
            if (current->val < maximum) {
                // Delete current by skipping
                prev->next = current->next;
                ListNode* deleted = current;
                current = current->next;
                deleted->next = nullptr;
            }

            // Current does not need to be deleted
            else {
                prev = current;
                current = current->next;
            }
        }
        
        // Reverse and return the modified linked list
        return reverseList(head);
    }
};