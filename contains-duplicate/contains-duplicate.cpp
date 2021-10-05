class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        int size = nums.size();
        
        for(int i = 0;i<size;i++){
            if(mp[nums[i]] !=0 && mp[nums[i]] != i + 1){
               return true; 
            }
            mp[nums[i]] = i + 1;
        }
        return false;
    }
};