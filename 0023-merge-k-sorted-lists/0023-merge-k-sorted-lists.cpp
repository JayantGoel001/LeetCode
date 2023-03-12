#define pil pair<int, ListNode*>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pil, vector<pil>, greater<pil>> pq;
        
        for(auto it : lists){
            if(it){
                pq.push({it->val, it});
            }
        }
        
        ListNode *res = new ListNode(0);
        ListNode *temp = res;
        
        while(!pq.empty()){
            pil top = pq.top();
            
            temp->next = new ListNode(top.first);
            pq.pop();
            
            if(top.second->next){
                pq.push({top.second->next->val, top.second->next});
            }
            temp = temp->next;
        }
        
        return res->next;
    }
};