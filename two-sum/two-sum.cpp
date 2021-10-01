class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            int x = target - nums[i];
            if(mp[x] != 0 && mp[x] != i + 1){
                return {i,mp[x]-1};
            }
            mp[nums[i]] = i + 1;
        }
        return {-1,-1};
    }
};