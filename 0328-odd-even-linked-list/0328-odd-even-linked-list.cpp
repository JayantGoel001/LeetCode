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
        ListNode *odd = new ListNode(0);
        ListNode *temp1 = odd;
        ListNode *even = new ListNode(0);
        ListNode *temp2 = even;

        while(head) {
            temp1->next = head;
            temp1 = temp1->next;
            temp2->next = head->next;
            temp2 = temp2->next;

            head = head->next ? head->next->next: nullptr;
        }

        temp1->next = even->next;

        return odd->next;
    }
};