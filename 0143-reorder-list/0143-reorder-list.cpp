class Solution {
public:
    ListNode *reverse(ListNode *head){
        if(!head){
            return head;
        }
        ListNode *temp = head;
        
        while(temp->next){
            temp = temp->next;
        }
        
        while(head != temp){
            ListNode *next = temp->next;
            temp->next = new ListNode(head->val);
            temp->next->next = next;
            head = head->next;
        }
        return temp;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next){
            return;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *rev = reverse(slow->next);
        slow->next = nullptr;
        
        slow = head;
        while(slow && rev){
            ListNode *next = slow->next;
            
            slow->next = new ListNode(rev->val);
            slow->next->next = next;
            
            slow = next;
            rev = rev->next;
        }
    }
};