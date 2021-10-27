class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *temp = head;
        int carry = 0;
        while(l1 && l2){
            int x = carry + l1->val + l2->val;
            carry = x/10;
            if(!head){
                temp = new ListNode(x%10);
                head = temp;
            }else{
                temp->next = new ListNode(x%10);
                temp = temp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int x = carry + l1->val;
            carry = x/10;
            if(!head){
                temp = new ListNode(x%10);
                head = temp;
            }else{
                temp->next = new ListNode(x%10);
                temp = temp->next;
            }
            l1 = l1->next;
        }
        while(l2){
            int x = carry + l2->val;
            carry = x/10;
            if(!head){
                temp = new ListNode(x%10);
                head = temp;
            }else{
                temp->next = new ListNode(x%10);
                temp = temp->next;
            }
            l2 = l2->next;
        }
        if(carry){
            temp->next = new ListNode(carry);
        }
        return head;
    }
};