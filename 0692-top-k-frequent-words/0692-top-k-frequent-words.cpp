#define pis pair<int,string>
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto it : words){
            mp[it]++;
        }
        
        auto cmp = [](pis &str1, pis &str2){
            if(str1.first == str2.first){
                return str1.second < str2.second;
            }
            return str1.first > str2.first;
        };
        
        priority_queue<pis,vector<pis>, decltype(cmp)> pq(cmp);
        
        for(auto it : mp){
            pq.push({it.second, it.first});
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