class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return toBST(head, nullptr);
    }
    TreeNode* toBST(ListNode *head, ListNode *tail){
        if(head == tail){
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode *root = new TreeNode(slow->val);
        
        root->left = toBST(head, slow);
        root->right = toBST(slow->next, tail);
        
        return root;
    }
};