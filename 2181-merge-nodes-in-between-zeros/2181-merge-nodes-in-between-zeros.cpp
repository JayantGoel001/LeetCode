class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode *temp = head;
        ListNode *nHead = new ListNode(0);
        ListNode *curr = nHead;
        bool first = true;
        while(temp){
            if(temp->val == 0){
                if(sum !=0){
                    curr->next = new ListNode(sum);
                    curr = curr->next;
                    sum = 0;
                }
            }
            sum += temp->val;
            
            temp = temp->next;
        }
        return nHead->next;
    }
};