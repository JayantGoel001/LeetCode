class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        for(int i=0;i<nums.size();i++) {
            if(i != 0) nums[i] += nums[i - 1];
            
            nums[i] %= k;
        }
        
        unordered_map<int,int> mp;
        mp[0] = -1;
        
        for(int i=0;i<nums.size();i++) {
            if(mp.contains(nums[i]) && i - mp[nums[i]] >= 2) {
                return true;
            } 
            
            if (!mp.contains(nums[i])) {
                mp[nums[i]] = i;
            }
        }
        
        return false;
    }
};