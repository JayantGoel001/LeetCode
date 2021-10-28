class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *temp = head;
        
        while(temp){
            if(temp->next && temp->val == temp->next->val){
                while(temp->next && temp->val == temp->next->val){
                    temp = temp->next;
                }
                if(prev){
                    prev->next = temp->next;
                }else{
                    head = temp->next;
                }
            }else{
                prev = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};