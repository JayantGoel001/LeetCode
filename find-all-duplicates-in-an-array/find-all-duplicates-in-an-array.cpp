class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        
        vector<int> v;
        for(auto it:nums){
            if(s.find(it) != s.end()){
                v.push_back(it);
            }
            s.insert(it);
        }
        
        return v;
    }
};