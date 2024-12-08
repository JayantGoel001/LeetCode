class Solution {
public:
    ListNode* merge(ListNode* s1, ListNode* s2) {
        ListNode* head = nullptr;
        ListNode* temp = nullptr;
        while (s1 && s2) {
            if (s1->val < s2->val) {
                if (!head) {
                    temp = s1;
                    head = temp;
                } else {
                    temp->next = s1;
                    temp = temp->next;
                }
                s1 = s1->next;
            } else {
                if (!head) {
                    temp = s2;
                    head = temp;
                } else {
                    temp->next = s2;
                    temp = temp->next;
                }
                s2 = s2->next;
            }
        }
        if (s1) {
            temp->next = s1;
        }
        if (s2) {
            temp->next = s2;
        }

        return head;
    }

    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next)
            return head;

        if (!head->next->next) {
            if (head->val > head->next->val) {
                int data = head->val;
                head->val = head->next->val;
                head->next->val = data;
            }
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        head = mergeSort(head);
        slow = mergeSort(slow);

        return merge(head, slow);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};