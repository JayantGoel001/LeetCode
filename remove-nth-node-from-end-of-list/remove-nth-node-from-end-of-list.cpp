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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *nth = head;
        while(nth && n--){
            nth = nth->next;
        }
        ListNode *prev = nullptr;
        ListNode *temp = head;
        while(nth && temp){
            nth = nth->next;
            prev = temp;
            temp = temp->next;
        }
        if(prev){
            prev->next = temp->next;
        }else{
            head = head->next;
        }
        return head;
    }
};