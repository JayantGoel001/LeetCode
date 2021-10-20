class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *newHead = new ListNode(0,head);
        ListNode *prev = newHead;
        
        while(head){
            if(head->next && head->val == head->next->val){
                while(head->next && head->val == head->next->val){
                    head = head->next;
                }
                prev->next = head->next;
            }else{
                prev = prev->next;
            }
            head = head->next;
        }
        return newHead->next;
    }
};