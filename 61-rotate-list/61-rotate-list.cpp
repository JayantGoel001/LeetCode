class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return nullptr;
        }
        int count = 0;
        ListNode *temp = head;
        while(temp){
            temp = temp->next;
            count++;
        }
        k = k%count;
        
        if(k == 0){
            return head;
        }
        
        
        ListNode *fast = head;
        
        while(k--){
            fast = fast->next;
        }
        ListNode *slow = head;
        ListNode *prev = nullptr;
        while(slow && fast){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = nullptr;
        
        ListNode *res = slow;
        
        while(slow->next){
            slow = slow->next;
        }
        slow->next = head;
        
        return res;
    }
};