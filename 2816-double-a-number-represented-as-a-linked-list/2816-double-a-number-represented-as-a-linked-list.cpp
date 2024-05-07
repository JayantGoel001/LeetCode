class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        // If the value of the head node is greater than 4, insert a new node at the beginning
        if (head->val > 4) {
            head = new ListNode(0, head);
        }
        
        // Traverse the linked list
        for (ListNode* node = head; node != nullptr; node = node->next) {
            // Double the value of the current node and update it with the units digit
            node->val = (node->val * 2) % 10;
            
            // If the current node has a next node 
            // and the next node's value is greater than 4,
            // increment the current node's value to handle carry
            if (node->next != nullptr && node->next->val > 4) {
                node->val++;
            }
        }
        
        return head;
    }
};