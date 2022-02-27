class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head){
            ListNode *temp = head;
            while(temp->next){
                temp = temp->next;
            }
            ListNode *curr = temp;
            
            while(head != curr){
                ListNode *next = temp->next;
                temp->next = new ListNode(head->val);
                temp->next->next = next;
                head = head->next;
            }
            
            return curr;
        }
        return nullptr;
    }
};