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
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode *copy = head;
        
        while(copy){
            st.push(copy->val);
            copy = copy->next;
        }
        int maxi = 0;
        int size = st.size()/2;
        
        for(int i=0;i<size;i++){
            maxi = max(maxi, st.top() + head->val);
            st.pop();
            head = head->next;
        }
        return maxi;
    }
};