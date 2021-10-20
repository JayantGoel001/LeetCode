#define pii pair<int,int>
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        int size = arr.size();
        
        for(auto it : arr){
            mp[it]++;
        }
        priority_queue<pii> pq;
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        int count = 0;
        while(!pq.empty()){
            count += pq.top().first;
            pq.pop();
            
            if(count >= size/2){
                return mp.size() - pq.size();
            }
        }
        return size;
    }
};