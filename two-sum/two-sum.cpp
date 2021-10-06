class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp[target - nums[i]] != 0 && mp[target - nums[i]] != i+1){
                return {i,mp[target - nums[i]]-1};
            }
            mp[nums[i]] = i + 1;
        }
        return {-1,-1};
    }
};