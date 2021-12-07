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
    int getDecimalValue(ListNode* head) {
        int n = 0;
        
        ListNode *temp = head;
        
        while(temp){
            temp = temp->next;
            n++;
        }
        
        int num = 0;
        while(head){
            num += head->val * pow(2,n-1);
            n--;
            head = head->next;
        }
        return num;
    }
};