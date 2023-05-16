class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dm = new ListNode(0);
        dm->next = head;
        
        ListNode *temp = dm;
        
        while(temp->next && temp->next->next){
            ListNode *first = temp->next;
            ListNode *second = temp->next->next;
            
            first->next = second->next;
            temp->next = second;
            temp->next->next = first;
            
            temp = temp->next->next;
        }
        return dm->next;
    }
};