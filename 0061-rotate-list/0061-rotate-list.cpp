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
    int size(ListNode *head) {
        int count = 0;
        while(head) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        k %= size(head);
        if (k == 0) return head;

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && k--) fast = fast->next;

        ListNode *prev = nullptr;
        while(slow && fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = nullptr;

        ListNode *newHead = slow;
        while(slow && slow->next) slow = slow->next;
        if(slow) slow->next = head;

        return newHead;
    }
};