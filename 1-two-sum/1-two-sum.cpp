class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            if(mp[target - nums[i]] != 0){
                return {i,mp[target - nums[i]]-1};
            }
            mp[nums[i]] = i + 1;
        }
        return {-1,-1};
    }
};