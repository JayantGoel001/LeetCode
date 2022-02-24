class Solution {
public:
    
    ListNode* sortList(ListNode* head) {
        if(head && head->next){
            ListNode *mid = getMid(head);
            ListNode *left = sortList(head);
            ListNode *right = sortList(mid);
            
            return merge(left,right);
        }
        return head;
    }
    
    ListNode *getMid(ListNode *head){
        ListNode *fast = head;
        ListNode *prev = nullptr;
        while(fast && fast->next && head){
            prev = head;
            head = head->next;
            fast = fast->next->next;
        }
        if(prev){
            prev->next = nullptr;
        }
        
        return head;
    }
    
    ListNode *merge(ListNode *left,ListNode *right){
        ListNode *temp = new ListNode(0);
        ListNode *curr = temp;
        
        while(left && right){
            if(left->val < right->val){
                curr->next = new ListNode(left->val);
                left = left->next;
            }else{
                curr->next = new ListNode(right->val);
                right = right->next;
            }
            curr = curr->next;
        }
        while(left){
            curr->next = new ListNode(left->val);
            left = left->next;
            curr = curr->next;
        }
        
        while(right){
            curr->next = new ListNode(right->val);
            right = right->next;
            curr = curr->next;
        }
        
        return temp->next;
    }
};