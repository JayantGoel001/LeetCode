class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head){
            ListNode *curr = head;
            ListNode *prev = nullptr;
            while(curr){
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            return prev;
        }
        return nullptr;
    }
};