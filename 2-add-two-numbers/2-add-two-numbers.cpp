class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp = new ListNode(0);
        ListNode *head = temp;
        
        int carry = 0;
        while(l1 && l2){
            temp->next = new ListNode((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry)/10;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1){
            temp->next = new ListNode((l1->val + carry)%10);
            carry = (l1->val + carry)/10;
            temp = temp->next;
            l1 = l1->next;
        }
        
        while(l2){
            temp->next = new ListNode((l2->val + carry)%10);
            carry = (l2->val + carry)/10;
            temp = temp->next;
            l2 = l2->next;
        }
        if(carry){
            temp->next = new ListNode(carry);
        }
        return head->next;
    }
};