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
    bool isPalindrome(ListNode* head) {
        int count = 0;
        ListNode *temp = head;
        while(temp){
            temp = temp->next;
            count++;
        }
        int x = count/2;
        ListNode *curr = head;
        ListNode *prev = nullptr;
        
        while(x--){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        if(count%2){
            curr = curr->next;
        }
        
        while(prev && curr){
            if(prev->val != curr->val){
                return false;
            }
            prev = prev->next;
            curr = curr->next;
        }
        return true;
    }
};