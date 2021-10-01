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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode *temp = head;
        int c = 0;
        while(temp){
            st.push(temp);
            temp = temp->next;
            c++;
        }
        
        int x = c/2;
        
        temp = head;
        while(temp && x--){
            ListNode *next = temp->next;
            
            temp->next = st.top();
            st.pop();
            
            temp = temp->next;
            temp->next = next;
            temp = temp->next;
        }
        
        
        temp->next = nullptr;
    }
};