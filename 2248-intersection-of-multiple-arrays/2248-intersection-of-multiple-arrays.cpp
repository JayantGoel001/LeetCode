class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> mp(1001,0);
        for(auto num : nums){
            for(auto it : num){
                mp[it]++;
            }
        }
        vector<int> v;
        for(int i=0;i<=1000;i++){
            if(mp[i] == nums.size()){
                v.push_back(i);
            }
        }
        return v;
    }
};