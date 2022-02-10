class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        for(auto it : nums){
            sum += it;
            
            if(mp[sum - k]!=0){
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
    }
};