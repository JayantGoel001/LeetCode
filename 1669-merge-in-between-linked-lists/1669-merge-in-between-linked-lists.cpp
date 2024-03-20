class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *head = list1;
        ListNode *curr = list1;
        ListNode *prev = nullptr;
        ListNode *aNode = nullptr;
        ListNode *bNode = nullptr;
        
        while(list1){
            if(a == 0){
                aNode = prev;
            }
            if(b == 0){
                bNode = list1;
                break;
            }
            prev = list1;
            list1 = list1->next;
            a--;
            b--;
        }
        
        aNode->next = list2;
        
        while(list2->next){
            list2 = list2->next;
        }
        
        list2->next = bNode->next;
        
        return head;
    }
};