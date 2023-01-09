class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list = new ListNode(0);
        ListNode *head = list;
        while(list1 && list2){
            if(list1->val >= list2->val){
                list->next = new ListNode(list2->val);
                list2 = list2->next;
            }else{
                list->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            list = list->next;
        }
        if(list1){
            list->next = list1;
        }
        if(list2){
            list->next = list2;
        }
        return head->next;
    }
};