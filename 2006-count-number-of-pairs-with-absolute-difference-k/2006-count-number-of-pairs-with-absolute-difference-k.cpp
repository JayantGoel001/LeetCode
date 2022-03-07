class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        int count = 0;
        for(auto it : nums){
            count += mp[it + k] + mp[it - k];
            mp[it]++;
        }
        return count;
    }
};