class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mp(k,0);
        
        int count = 0;
        int prev = 0;
        mp[0] = 1;
        for(auto it : nums){
            prev = ((prev + it) % k + k) % k;
            count += mp[prev];
            mp[prev]++;
        }
        return count;
    }
};