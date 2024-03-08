class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num: nums){
            mp[num]++;
        }
        
        int maxi = 0;
        for(auto it : mp){
            maxi = max(maxi, it.second);
        }
        
        int count = 0;
        
        for(auto num: nums) {
            count += mp[num] == maxi;
        }
        
        return count;
    }
};