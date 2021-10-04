#define pii pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int size = nums.size();
        if(k == size){
            return nums;
        }
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        
        map<int,int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        
        for(auto it : mp){
            pq.push({it.second,it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> v(k);
        while(k--){
            v[k] = pq.top().second;
            pq.pop();
        }
        return v;
    }
};