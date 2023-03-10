class Solution {
public:
    ListNode *root;
    Solution(ListNode* head) {
        root = head;
    }
    
    int getRandom() {
        int scope = 1;
        int ch = 0;
        ListNode *head = root;
        while(head){
            if((double)rand()/RAND_MAX < 1.0 / scope){
                ch = head->val;
            }
            scope++;
            head = head->next;
        }
        return ch;
    }
};