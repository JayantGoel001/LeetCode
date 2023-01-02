class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        unordered_map<int,bool> mp;
        
        for(auto it : nums){
            mp[it] = true;
            count += mp[it - diff] && mp[it - 2 * diff];
        }
        return count;
    }
};