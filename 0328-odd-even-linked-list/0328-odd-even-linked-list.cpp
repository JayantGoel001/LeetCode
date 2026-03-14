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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
        
        ListNode *odd = head;
        ListNode *even = new ListNode(-1);
        ListNode *dummy = even;

        int isOdd = true;
        ListNode *prev = nullptr;
        while(odd) {
            if (odd->next) {
                even->next = odd->next;
                even = even->next;
                odd->next = odd->next->next;
            }
            prev = odd;
            odd = odd->next;
        }
        prev->next = dummy->next;
        even->next = nullptr;

        return head;
    }
};