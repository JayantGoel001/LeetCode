/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        do{
            if(!slow || !fast || !fast->next){
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
        }while(slow != fast);
        
        fast = head;
        
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};