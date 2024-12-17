#define pci pair<char,int>
class Solution {
public:
    string repeatLimitedString(string s, int k) {
        priority_queue<pci> pq;
        unordered_map<char,int> mp;
        for(auto it : s){
            mp[it]++;
        }
        for(auto it : mp){
            pq.push({it.first,it.second});
        }
        string str = "";
        while(!pq.empty()){
            pci top = pq.top();
            pq.pop();
            int x = min(top.second,k);
            while(x--){
                str += top.first;
            }
            if(top.second > k){
                pci last = {top.first,top.second-k};
                if(!pq.empty()){
                    top = pq.top();
                    pq.pop();
                       
                    str += top.first;
                    pq.push(last);
                    if(top.second - 1 > 0){
                        pq.push({top.first,top.second-1});
                    }
                }
            }
        }
        return str;
    }
};