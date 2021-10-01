/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 && l2){
            ListNode *l3 = new ListNode();
            ListNode *head = l3;
            while(l1 && l2){
                if(l1->val < l2->val){
                    l3->next = new ListNode(l1->val);
                    l1 = l1->next;
                }else{
                    l3->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
                l3 = l3->next;
            }
            while(l1){
                l3->next = new ListNode(l1->val);
                l1 = l1->next;
                l3 = l3->next;
            }
            while(l2){
                l3->next = new ListNode(l2->val);
                l2 = l2->next;
                l3 = l3->next;
            }
            return head->next;
        }else{
            if(l1){
                return l1;
            }else{
                return l2;
            }
        }
    }
};