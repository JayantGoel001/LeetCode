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
    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr;
        while(head) {
            ListNode *next = head->next;

            head->next = prev;
            prev = head;

            head = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        if (!head) return 0;

        ListNode *slow = head;
        ListNode *fast = head;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverse(slow);

        int maxi = 0;
        while(head && slow) {
            maxi = max(maxi, head->val + slow->val);
            head = head->next;
            slow = slow->next;
        }

        return maxi;
    }
};