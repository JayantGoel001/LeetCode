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
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        ListNode *tail = head;
        
        while(tail->next){
            tail = tail->next;
        }
        ListNode *temp = head;
        
        while(temp!=tail){
            ListNode *next = tail->next;
            tail->next = new ListNode(temp->val);
            tail->next->next = next;
            temp = temp->next;
        }
        
        return tail;
    }
};