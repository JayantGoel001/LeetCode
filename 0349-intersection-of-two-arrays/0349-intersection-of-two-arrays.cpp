class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        
        for(auto it : nums2){
            mp[it]++;
        }
        
        vector<int> res;
        
        for(auto it : nums1){
            if(mp[it]){
                res.push_back(it);
                mp[it]=0;
            }
        }
        return res;
    }
};