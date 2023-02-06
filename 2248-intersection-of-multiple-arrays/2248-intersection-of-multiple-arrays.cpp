class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int> mp;
        for(auto num : nums){
            for(auto it : num){
                mp[it]++;
            }
        }
        vector<int> v;
        for(auto it : mp){
            if(it.second == nums.size()){
                v.push_back(it.first);
            }
        }
        return v;
    }
};