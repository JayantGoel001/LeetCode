class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(auto it : nums){
            mp[it]++;
        }
        
        vector<int> res(2,0);
        for(auto it : mp){
            res[0] += it.second/2;
            res[1] += it.second%2;
        }
        return res;
    }
};