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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* head = l1;
        ListNode* head1 = l1;
        ListNode* head2 = l2;

        ListNode* prev = nullptr;
        while (l1 && l2) {
            int x = l1->val + l2->val + carry;
            carry = x / 10;
            l1->val = x % 10;
            l2->val = x % 10;

            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            head = head1;
            int x = l1->val + carry;
            carry = x / 10;
            l1->val = x % 10;

            prev = l1;
            l1 = l1->next;
        }

        while (l2) {
            head = head2;
            int x = l2->val + carry;
            carry = x / 10;

            l2->val = x % 10;

            prev = l2;
            l2 = l2->next;
        }

        if (carry && prev)
            prev->next = new ListNode(carry);

        return head;
    }
};