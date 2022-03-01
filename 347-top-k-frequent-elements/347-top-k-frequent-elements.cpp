#define pii pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        if(k == nums.size()){
            return nums;
        }
        
        unordered_map<int,int> mp;
        
        for(auto it : nums){
            mp[it]++;
        }
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        
        for(auto it : mp){
            pq.push({it.second,it.first});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> v;
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};