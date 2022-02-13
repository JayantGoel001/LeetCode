class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp = new ListNode(0);
        ListNode *head = temp;
        while(list1 && list2){
            if(list1->val < list2->val){
                temp->next = new ListNode(list1->val);
                list1 = list1->next;
            }else{
                temp->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if(list1){
            temp->next = list1;
        }
        if(list2){
            temp->next = list2;
        }
        return head->next;
    }
};