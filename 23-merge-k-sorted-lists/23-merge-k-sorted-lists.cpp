#define pil pair<int,ListNode*>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pil,vector<pil>,greater<pil>> pq;
        
        for(auto it : lists){
            if(it){
                pq.push({it->val,it});
            }
        }
        
        ListNode *temp = new ListNode();
        ListNode *head = temp;
        while(!pq.empty()){
            pil top = pq.top();
            pq.pop();
            
            temp->next = top.second;
            
            if(top.second->next){
                pq.push({top.second->next->val,top.second->next});
            }
            temp = temp->next;
        }
        return head->next;
    }
};