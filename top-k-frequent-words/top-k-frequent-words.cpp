#define pis pair<int,string>
class Solution {
public:
    
    static bool cmp(pis p1,pis p2){
        if(p1.first == p2.first){
            return p1.second < p2.second;
        }
        return p1.first > p2.first;
    }    
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pis,vector<pis>,decltype(&cmp)> pq(cmp);
        unordered_map<string,int> mp;
        
        for(auto it : words){
            mp[it]++;
        }
        for(auto it : mp){
            pq.push({it.second,it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<string> v(k);
        while(!pq.empty()){
            v[--k] = pq.top().second;
            pq.pop();
        }
        return v;
    }
};