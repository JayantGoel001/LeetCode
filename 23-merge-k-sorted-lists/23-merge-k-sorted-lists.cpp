#define pil pair<int,ListNode*>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        priority_queue<pil,vector<pil>,greater<pil>> pq;
        
        ListNode *temp = new ListNode(0);
        ListNode *head = temp;
        
        for(auto it : lists){
            if(it){
                pq.push({it->val,it});
            }
        }
        while(!pq.empty()){
            pil top = pq.top();
            pq.pop();
            
            temp->next = top.second;
            temp = temp->next;
            
            if(top.second->next){
                pq.push({top.second->next->val,top.second->next});
            }
        }
        
        return head->next;
    }
};