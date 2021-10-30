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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head){
            int count = 0;
            ListNode *curr = head;
            ListNode *prev = nullptr;
            ListNode *temp = head;
            
            while(temp){
                temp = temp->next;
                count++;
            }
            if(count>=k){
                count = 0;
                while(count<k && curr){
                    temp = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = temp;
                    count++;
                }
                if(temp){
                    head->next = reverseKGroup(temp,k);
                }
                return prev;
            }else{
                return head;
            }
        }else{
            return nullptr;
        }
    }
};