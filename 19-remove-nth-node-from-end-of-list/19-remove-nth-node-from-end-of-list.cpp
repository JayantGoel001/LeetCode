class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        
        while(fast && n--){
            fast = fast->next;
        }
        ListNode *slow = head;
        ListNode *prev = nullptr;
        while(slow && fast){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        if(prev){
            prev->next = slow->next;
        }else{
            head = head->next;
        }
        return head;
    }
};