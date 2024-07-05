class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;
        
        int i = 0;
        ListNode *temp = head;
        ListNode *prev = nullptr;
        while(temp){
            if(prev!=nullptr && temp->next!=nullptr){
                if((prev->val < temp->val && temp->val > temp->next->val) || (prev->val > temp->val && temp->val < temp->next->val)){
                    critical.push_back(i);
                }
            }
            i++;
            prev = temp;
            temp = temp->next;
        }
        vector<int> res(2);
        if(critical.size() <= 1){
            return {-1,-1};
        }
        res[0] = INT_MAX;
        for(int i=0;i<critical.size()-1;i++){
            res[0] = min(res[0],critical[i+1] - critical[i]);
        }
        res[1] = critical.back() - critical[0];
        
        return res;
    }
};