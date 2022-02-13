class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast && slow && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};