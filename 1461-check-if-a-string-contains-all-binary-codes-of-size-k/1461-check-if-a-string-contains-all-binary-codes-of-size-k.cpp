class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> ust;
        deque<char> dq;
        
        for(int i=0;i<s.size();i++){
            dq.push_back(s[i]);
            if(i >= k - 1){
                ust.insert({dq.begin(),dq.end()});
                dq.pop_front();
            }
        }
        
        return ust.size() == 1<<k;
    }
};